### 解题思路
此处撰写解题思路

### 代码

```c
void sortColors(int* nums, int numsSize){
    if(numsSize == 0) return;
    int m=0,n=0,k=0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == 0) {
            m++;
        } else if(nums[i] == 1) {
            n++;
        } else {
            k++;
        } 
    }
    for(int i = 0; i < numsSize; i++) {
        if(i < m) {
            nums[i] = 0;
        }
        else if(i < m+n && i >= m){
            nums[i] = 1;
        }
        else {
            nums[i] = 2;
        }
    }
}
```