### 解题思路
逐步检索进行判断

### 代码

```c
int compare(const void * p1,const void * p2)
{
    return *(int*)p1 - *(int*)p2;
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    qsort(nums,numsSize,sizeof(int),compare);
    //找出与目标值最接近的数
    int res = nums[0] + nums[1] + nums[2];
	int sumtemp = 0;
    for(int i =0;i<numsSize - 2;i++)
    {
        int j = i+1;
        int k = numsSize-1;
        while(j<k)
        {
            sumtemp = nums[i] + nums[j] + nums[k];
            if(abs(sumtemp - target ) < abs(res - target ))
            {
                res = sumtemp;
            }

            if(sumtemp < target) j++;
            else if(sumtemp >target) k--;
            else break;
        }
    }
	
	return res;
}
```