### 解题思路
此处撰写解题思路

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int i,j;
    for(i=0,j=0;j<numsSize;j++){
        if(nums[j]!=val){
            nums[i]=nums[j];
            i++;
        }
    }
    return i;
}
```