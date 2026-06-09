### 解题思路
此处撰写解题思路

### 代码

```c
void moveZeroes(int* nums, int numsSize){
    int i = 0 ;
    int* res = ( int* )(malloc((sizeof(int))*numsSize)) ;
    int left = 0 , right = numsSize - 1 ;
    for( i = 0 ; i < numsSize ; i++)
    {
        if(nums[i] == 0)
        {
            res[right] = 0 ;
            right -- ;
        }
        else{
            res[left] = nums[i] ;
            left ++ ;
        }
        
    }
    for( i = 0 ; i < numsSize ; i++)
    {
        nums[i] = res[i] ;
    }
    
}
```