### 解题思路
按照end进行排序，下面的只要start小于end的，则一只就可以，否则个数++

### 代码

```c


/*算法思想，按照end排序，end最小的地方射出第一件，第一件射出后，看看第一键盘穿透的气球，如果穿透了，则标志职位true*/


int comparearry(const void *a, const void * b)
{
    int *aa = *(int **)a;
    int *bb = *(int **)b;
    return aa[1] - bb[1];
}


int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){


if(points == 0 || pointsSize == 0) {
    return 0;
}
if(pointsSize == 1) {
    return 1;
}
int needs = 0;
qsort(points,pointsSize,sizeof(int *),comparearry);

int visit[pointsSize];

for(int i = 0; i < pointsSize; i++)
{
    visit[i] = 0;
    printf("%d %d \r\n", points[i][0], points[i][1]);
}

needs = 1;
visit[0] = 1;
int end = points[0][1];
for(int i = 1; i <pointsSize; i++) {
   if(points[i][0] <= end)
   {
       visit[i] = 1;
       continue;
   }
   else
   {
       needs++;
       end = points[i][1];
   }
}


return needs;


}
```