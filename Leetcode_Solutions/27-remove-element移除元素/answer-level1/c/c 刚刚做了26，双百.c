### 解题思路
此处撰写解题思路

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int k=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=val){
            nums[k]=nums[i];
            k++;
        }
    }
    return k;
}
```