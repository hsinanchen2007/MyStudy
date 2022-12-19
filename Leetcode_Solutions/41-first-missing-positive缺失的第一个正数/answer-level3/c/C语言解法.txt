

### 代码

```c
int firstMissingPositive(int* nums, int numsSize){
    if(numsSize == 0)
        return 1;
    int* arr = (int*)malloc(sizeof(int)*(numsSize+2));
    int i,x;
    for(i=0;i<numsSize;i++)
    {
        x = nums[i];
        if(x<=numsSize&&x>0)
        {
            arr[x] = x;
        }
    }
    for(i=1;i<=numsSize+1;i++)
    {
        if(arr[i] != i)
            break;
    }
    return i;
}
```