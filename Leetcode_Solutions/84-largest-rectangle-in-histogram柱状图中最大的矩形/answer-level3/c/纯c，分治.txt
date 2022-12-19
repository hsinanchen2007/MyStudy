### 解题思路
以最低处为分界线，分成左右两部分，计算其最大面积

### 代码

```c
//设置头尾指针，每次移动低那边的指针
int searchminidx(int* heights, int low, int high)
{
    int min_idx=low;
    int min=heights[low];
    for(int i=low+1; i<=high; i++)
    {
        if(heights[i]<min)
        {
            min_idx=i;
            min=heights[i];
        }
    }
    return min_idx;
}
int helper(int* heights, int low, int high)
{
    if(low==high)
        return heights[low];
    
    int max_S=0;
    int tmp_idx;
    tmp_idx=searchminidx(heights,low,high);

    int cur_S=(high-low+1)*heights[tmp_idx];
    int left_S=0;
    int right_S=0;
    if(low<=(tmp_idx-1))
        left_S=helper(heights,low,tmp_idx-1);
    if((tmp_idx+1)<=high)
        right_S=helper(heights,tmp_idx+1,high);

    max_S=(max_S<cur_S)?cur_S:max_S;
    max_S=(max_S<left_S)?left_S:max_S;
    max_S=(max_S<right_S)?right_S:max_S;

    return max_S;
}
int largestRectangleArea(int* heights, int heightsSize){
    if(heightsSize==0) return 0;
    int low=0;
    int high=heightsSize-1;

    return helper(heights,low,high);

}
```