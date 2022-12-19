### 解题思路

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int i, j;
    for(i=0; i<numsSize; i++)
    {
        if(nums[i] == val)
        {
            j = i;
            while(j+1 < numsSize)
            {
                
                nums[j] =nums[j+1];
                j++;
            }
            numsSize--;
            i--;
        }

    }
    return numsSize;
}
```