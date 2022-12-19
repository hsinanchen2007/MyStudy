### 解题思路


### 代码

```c
void rotate(int* nums, int numsSize, int k){
        int a[numsSize];
        for (int i=0;i<numsSize;i++)
        {
            a[(i+k)%numsSize]=nums[i];
        }
        for(int i=0;i<numsSize; i++) 
        {
            nums[i]=a[i];
        }
}
```