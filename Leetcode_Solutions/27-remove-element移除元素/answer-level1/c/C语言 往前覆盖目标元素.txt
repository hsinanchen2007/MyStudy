```


int removeElement(int* nums, int numsSize, int val)
{
    int *p = nums;
    int i,x;
    for( i = 0; i< numsSize; )
    {
        if( *p == val )       // 如果与val相等 则将后面元素依次前移一格
        {
            i++;  
        for( x = i; x < numsSize; x++ ) 
                *(nums + x-1) = *(nums + x);
            numsSize--;
            i--;
        }
        else
        {
            i++;
            p = (nums + i);
        }
    }
    return numsSize;
}


```
