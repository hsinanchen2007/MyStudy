### 解题思路
1 将数组排序
2 重复的数据超过n/2，因此返回数组的中间值即可

### 代码

```c
void insertsort(int *a, int n)
{
    int tmp = a[0];
    int j = 0;
    int i = 0;
    for(i=1; i<n; i++)
    {
        j = i-1;
        tmp = a[i];
        for(;j>=0;j--)
        {
            if(a[j]>tmp)
            {
                a[j+1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1] = tmp; 
    }
    return;
}

int majorityElement(int* nums, int numsSize)
{
    int val = 0;

    if(numsSize == 0)
    {
        return 0;
    }

    insertsort(nums, numsSize);

    for(int i = 0; i<numsSize;i++)
    {
        printf("%d ", nums[i]);
    }

    if(numsSize%2 == 1)
    {
        val = nums[(numsSize+1)/2-1];
    }
    else
    {
        val = nums[numsSize/2];
    }
    return val;
}
```