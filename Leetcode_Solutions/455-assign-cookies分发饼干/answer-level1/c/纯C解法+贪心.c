### 解题思路
给胃口为g的小孩赋给满足尺寸为s的饼干；s的值是数组中满足s>=g的最小值
所以首先要进行排序

### 代码
//冒泡排序
```c
void BubbleSort(int *nums, int numsSize)
{
    for(int i=0;i<numsSize-1;i++)
    {
        int flag=1;
        for(int j=numsSize-1;j>i;j--)
        {
            if(nums[j-1]>nums[j])
            {
                int tmp=nums[j-1];
                nums[j-1]=nums[j];
                nums[j]=tmp;
                flag=0;
            }
        }
        if(flag)
            return;
    }
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    BubbleSort(g, gSize);
    BubbleSort(s, sSize);
    int sum=0;
    int flag=0; //flag标记分配到第几块饼干
    for(int i=0;i<gSize;i++)
    {
        for(int j=flag;j<sSize;j++)
        {
            if(g[i]<=s[j])
            {
                sum++;
                flag=j+1;
                break;
            }
        }
        if(flag>sSize)
            break;
    }
    return sum;
}
```