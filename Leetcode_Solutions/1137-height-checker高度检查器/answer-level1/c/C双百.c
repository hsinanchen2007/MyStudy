### 解题思路
此处撰写解题思路
先排序，然后比较
### 代码

```c
int cmp(int *a,int *b)
{
    return *a - *b;
}
int heightChecker(int* heights, int heightsSize)
{
    int *tmp = (char *)malloc(sizeof(int ) * heightsSize);
    int i;
    for(i = 0;i < heightsSize;i++)
    {
        *(tmp + i) = *(heights + i);
    }
    qsort(heights,heightsSize,sizeof(int),cmp);
    int count = 0;
    for(i = 0;i < heightsSize;i++)
    {
        if(*(heights + i) != *(tmp + i))
        {
            count++;
        }
    }
    return count;
}
```