尝试两个做法：

1、DFS or 回溯：以当前格子为起跳index，每次跳 1~nums[index]步，直到达到终点，保存下跳的最少的次数。但该方法超时。

void dfs(int* nums, int numsSize, int index, int count, int* minCount)
{
    int i, j;
    if(index>=numsSize-1)
    {
        if((*minCount) > count)
            *minCount = count;
    }
    else
    {
            for(j=1; j<=nums[index]; j++)
            {
                count++;
                dfs(nums, numsSize, index+j, count, minCount);
                count--;

            }
    }
}

int jump(int* nums, int numsSize)
{
    int i, j, count=0;
    int end = 0;
    int position = 0;
    int maxavailable = 0; 
    dfs(nums, numsSize, 0, count, &minCount);
      
    return count;
}
2、贪心：遍历数组，每次查看当前格子能达到的最远位置i+nums[i]与一直的可达到的最远maxavailable做比较，取最大值做本次跳跃的终点。每当遍历到本次跳跃终点就级数加1.
void dfs(int* nums, int numsSize, int index, int count, int* minCount)
{
    int i, j;
    if(index>=numsSize-1)
    {
        if((*minCount) > count)
            *minCount = count;
    }
    else
    {
        //for(i=index; i<numsSize; i++)
        //{
            for(j=1; j<=nums[index]; j++)
            {
                count++;
                dfs(nums, numsSize, index+j, count, minCount);
                count--;

            }
        //}
    }
}

int jump(int* nums, int numsSize)
{
    int i, j, count=0;
    int end = 0;
    int position = 0;
    int maxavailable = 0; 
    for(i=0; i<numsSize-1;i++)
    {
        maxavailable = (maxavailable>i+nums[i])?maxavailable:(i+nums[i]);
        if(i==end)
        {
            end = maxavailable;
            count++;
        }
    }
      
    return count;
}