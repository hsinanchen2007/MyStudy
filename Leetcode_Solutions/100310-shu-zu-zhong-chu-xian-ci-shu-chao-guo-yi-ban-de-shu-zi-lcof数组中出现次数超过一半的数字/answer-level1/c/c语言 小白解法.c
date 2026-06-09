### 解题思路
根据官方的摩尔投票法编写代码。
### 代码

```c
int majorityElement(int* nums, int numsSize){

    int i = 0;

    int model ;//定义众数
    int votes;//定义票数
    int mark;//标记,1表示众数，-1表示非众数

    if(numsSize == 0)
    {
        return 0;
    }

    model = nums[0];//初始化首个元素为众数
    votes = 0;//初始化票数为0
    mark = 0;

    while(i < numsSize)
    {
        if(votes == 0)
        {
            model = nums[i++];//数组中下一个元素为新众数
            mark = 1;//新众数肯定得标记为1
        }
        
        else
        {
            if(model == nums[i++])
            {
                mark = 1;//标记为1，说明和上一个元素相等
            }
            else
            {
                mark = -1;//说明和上一个元素不等
            }
        }
        votes = votes+mark;//求票数
    }

    return model;
}
```