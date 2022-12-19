### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX_NUM 504

typedef struct{
    int x;
    int y;
}Dot;

Dot dots[504];

int cmpDot(const void* a, const void* b)
{
    Dot arg1 = *(const Dot *)a;
    Dot arg2 = *(const Dot *)b;
    if(arg1.x != arg2.x){
        return arg1.x - arg2.x;
    }
    return arg1.y - arg2.y;
}

int isExist(int left, int right, int x, int y)
{
	int i;
	int a = 0;
	int b = 0;
	for (i = left; i < right; i++) {
		if (dots[i].x == x && dots[i].y == y) {
			return 1;
		}
	}
	return 0;
}

int minAreaRect(int** points, int pointsSize, int* pointsColSize){
	int i;
	int j;

	int tx;
	int ty;
	int tPos;
	int tmp;
	int result = INT_MAX;
	for (i = 0; i < pointsSize; i++) {
		dots[i].x = points[i][0];
		dots[i].y = points[i][1];

	}
	qsort(dots, pointsSize, sizeof(Dot), cmpDot);
	printf("1 pointsSize %d \n", pointsSize);

	for (i = 0; i < pointsSize; i++) {
		for (j = i + 1; j < pointsSize; j++) {
			//printf("1 ix %d iy %d jx %d jy %d \n", dots[i].x, dots[i].y, dots[j].x, dots[j].y);
			if(dots[i].x == dots[j].x || dots[i].y == dots[j].y) {
				continue;
			}
			tmp = abs((dots[j].x - dots[i].x) * (dots[j].y - dots[i].y));

			if( tmp > result) {
				continue;
			}

			//printf("2 ix %d iy %d jx %d jy %d \n", dots[i].x, dots[i].y, dots[j].x, dots[j].y);
			if(isExist(0, pointsSize, dots[i].x, dots[j].y) && isExist(0, pointsSize, dots[j].x, dots[i].y)) {
				result = tmp;
			}
			//printf("3 ix %d iy %d jx %d jy %d \n", dots[i].x, dots[i].y, dots[j].x, dots[j].y);
		}
	}
	return result == INT_MAX ? 0 : result;
}
```