### 解题思路
此处撰写解题思路

### 代码

```c
int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
    if(pointsSize==1)
        return 0;
    int temp=0;
    for(int i=1;i<pointsSize;++i)
    {
        int a=abs(points[i][1]-points[i-1][1]);
        int b=abs(points[i][0]-points[i-1][0]);
        temp+=a>b? a:b;
    }
    return temp;
}
```