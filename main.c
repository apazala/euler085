// EulerHacker085.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <inttypes.h>

typedef struct
{
	int area;
	int rectangles;
}arearectangles;


arearectangles arr[10000];
int narr;

int maxarea[2010001];

void init()
{
	int triag[2101];
	int ntriag;

	triag[0] = 0;
	triag[1] = 1;
	for (ntriag = 2; triag[ntriag - 1] < 2010001; ntriag++)
		triag[ntriag] = ntriag + triag[ntriag - 1];


	for(int i = 1; i < ntriag; i++)
	{
		for(int j = 1; j < ntriag; j++)
		{
			int64_t nrectangles = triag[i] * triag[j];
			if (nrectangles > 2010000) break;

			int area = i*j;
			if (area > maxarea[nrectangles])
				maxarea[nrectangles] = area;
		}
	}

	for(int i = 1; i <= 2010000; i++)
	{
		if(maxarea[i])
		{
			arr[narr].area = maxarea[i];
			arr[narr].rectangles = i;
			narr++;
		}
	}
}

int low_bound(int value) {
	int low = 0;
	int high = narr - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) >> 1;
		if (arr[mid].rectangles >= value)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}

int main()
{
	init();



    int target = 2000000;

    if(maxarea[target])
    {
        printf("%d\n", maxarea[target]);
    }else
    {
        int i = low_bound(target);
        if(i==0)
        {
            printf("%d\n", arr[i].area);
        }else
        {
            int dist1 = target - arr[i - 1].rectangles;
            int dist2 = arr[i].rectangles - target;
            if (dist1 < dist2 || (dist1 == dist2 && arr[i - 1].area > arr[i].area))
                i--;

            printf("%d\n", arr[i].area);
        }
    }
	

    return 0;
}
