### 解题思路
数组长度为1，必能到达；不为1时，判断是否有0，且0之前的数据能否跳过0，能跳过，则能到达最后，若不能跳过，则不能到达最后。

### 代码

```c

bool canJump(int* nums, int numsSize){

    bool result = false;
    int i,j;
    int b[numsSize];
    if(numsSize==1)
    {
        return true;
    }

    for(i=0;i<(numsSize-1);i++)
    {
        b[i] = nums[i]+i;
        if(nums[i] == 0)
        {
             result = false;
            for(j = 0;j<(i);j++)
            {
                if(b[j]>i)
                {
                    result = true;
                    break;
                }
            }
            if(result != true)
            {
                return false;
            }

        }
    }
  
    return true;
}

```