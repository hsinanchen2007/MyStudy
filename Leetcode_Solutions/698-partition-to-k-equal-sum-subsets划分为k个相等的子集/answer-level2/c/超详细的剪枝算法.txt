### 解题思路
此处撰写解题思路
这道题是一道很典型的剪枝算法题目，下面我用注释来分析我的算法。
### 代码

```c
int visited[17];//如果某个元素已经被访问，我们就用visited数组来把该元素标识为1
int end;//end与k相等，所以当子集的个数与end相等时，就说明符合条件，返回true
int aver;//等于所有元素和除于k

bool dfs(int* nums, int numsSize, int nowLen, int nowGet, int pos)
{
    int i;

    if (pos >= numsSize)//当当前搜索到的位置超出数组的边界时，很明显不符合条件
        return false;
    
    if (nowGet == end)//当当前符合条件的子集个数等于k时，就说明符合条件，返回true
        return true;

    for (i = pos; i < numsSize; i++)
    {
        if (visited[i] != 1)//已经访问过的元素跳过
        {
            if (nowLen + nums[i] == aver)//当前获取子集的元素和等于平均值时，说明符合条件
            {
                visited[i] = 1;//元素的已访问标识

                /*最后一个参数的含义为，我们从第一个元素开始查找，如果第一个元素符合条件，我们就从第二个元素开始找，以此类推，当我们第n个子集符合条件时，我们就从第n + 1个元素开始查找,nowGet + 1个元素所对应的下标为nowGet*/
                if (dfs(nums, numsSize, 0, nowGet + 1/*子集个数增加1*/, nowGet))//判断后面的元素是否符合条件
                    return true;

                visited[i] = 0;//不符合条件的话，恢复为0
            }
            else if (nowLen + nums[i] < aver)
            {
//跟上面大同小异，不再详解
                visited[i] = 1;

                if (dfs(nums, numsSize, nowLen + nums[i], nowGet, i + 1))
                    return true;
                
                visited[i] = 0;
                
               for (; i + 1 < numsSize && nums[i] == nums[i + 1]; i++);//当该元素不符合条件，后面的与他一样的元素肯定不符合，可以跳过
            }
        }
    }

    return false;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k)
{
    memset(visited, 0, sizeof(visited));
    end = k;
    aver = 0;
    
    for (int i = 0; i < numsSize; i++)
        aver += nums[i];
    
    aver /= k;

    if (dfs(nums, numsSize, 0, 0, 0))
        return true;
    else
        return false;
}
```