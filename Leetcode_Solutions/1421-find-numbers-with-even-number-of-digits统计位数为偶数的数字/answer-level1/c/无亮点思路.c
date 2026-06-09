

```c
int findNumbers(int* nums, int numsSize){
    int i,count=0,ou=0;
    for(i=0;i<numsSize;i++)
    {
        while(nums[i]!=0)
        {
            nums[i]=nums[i]/10;
            ou++;
        }
        if(ou%2==0)
        {
            count++;   
        }
        ou=0;
    }
    return count;
}
```