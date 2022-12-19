### 解题思路
此处撰写解题思路

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    int i = 0;
    int flag = 0;
    if(numsSize == 0)
        return numsSize;
    for (int j = 1; j < numsSize; j++) {
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
            flag = 0;
        } else {
            if(flag == 0) {
                i++;
                nums[i] = nums[j];
                flag = 1;
            }
        }
    }
    return i + 1;
}
```