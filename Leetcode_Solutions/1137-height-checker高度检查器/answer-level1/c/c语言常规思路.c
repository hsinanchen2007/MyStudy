### 解题思路
选择排序

### 代码

```c
int heightChecker(int* heights, int heightsSize){
    int cnt=0;
    int num[heightsSize];
    for(int i=0;i<heightsSize;i++)
    {
        num[i]=heights[i];
    }
    for(int i=0;i<heightsSize;i++)
    {
        int min=i;
        for(int j=i;j<heightsSize;j++)
        {
            if(heights[j]<heights[min])
            {
                int temp=heights[j];
                heights[j]=heights[min];
                heights[min]=temp;
            }
        }
    }
    for(int i=0;i<heightsSize;i++)
    {
        if(heights[i]!=num[i])
        {
            cnt++;
        }
    }
    return cnt;
}
```