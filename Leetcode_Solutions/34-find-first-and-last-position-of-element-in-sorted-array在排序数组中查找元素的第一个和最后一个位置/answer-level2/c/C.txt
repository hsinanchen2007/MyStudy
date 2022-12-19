```


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int head = 0, tail = numsSize - 1, mid;
    int *ret = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    
    if( numsSize == 0 )
    {
        ret[0] = -1;
        ret[1] = -1;
        
        return ret;
    }
    
    if( numsSize == 1 )
    {
        if( nums[0] == target )
        {
            ret[0] = 0;
            ret[1] = 0;
        }
        else
        {
            ret[0] = -1;
            ret[1] = -1;
        }
        return ret;
    }
    
    if( numsSize == 2 )
    {
        if( nums[0] == target && nums[1] != target )
        {
            ret[0] = 0;
            ret[1] = 0;
        }
        if( nums[0] != target && nums[1] == target )
        {
            ret[0] = 1;
            ret[1] = 1;
        }
        if( nums[0] == target && nums[1] == target )
        {
            ret[0] = 0;
            ret[1] = 1;
        }
        else if( nums[0] != target && nums[1] != target )
        {
            ret[0] = -1;
            ret[1] = -1;
        }
        return ret;
    }
    
    mid = (head + tail) / 2;
    
    while( head != mid && tail != mid )
    {
        if( nums[mid] == target )
        {
            head = mid, tail = mid;
            while( head > 0 && nums[head-1] == target ) head--;
            while( tail < numsSize -1 && nums[tail+1] == target ) tail++;
            
            ret[0] = head;
            ret[1] = tail;
            
            return ret;
        }
        if( nums[mid] > target )
        {
            tail = mid;
            mid = (mid + head) / 2;
        }
        else
        {
            head = mid;
            mid = (mid + tail) / 2;
        }
    }
    
    if( nums[0] == target )
    {
        ret[0] = 0;
        ret[1] = 0;
        
        return ret;
    }
    else if( nums[numsSize-1] == target )
    {
        ret[0] = numsSize - 1;
        ret[1] = numsSize - 1;
        
        return ret;
    }
    
    ret[0] = -1;
    ret[1] = -1;
    
    return ret;
}

```
