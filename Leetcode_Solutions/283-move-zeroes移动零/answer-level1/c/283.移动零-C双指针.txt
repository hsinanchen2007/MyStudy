### 解题思路
快慢指针，直接将非0值挨个写入，最后剩下的全补0
### 代码

```c
void moveZeroes(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return;
    }  

    int slow = 0;
    int fast = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[fast] != 0 ){
            nums[slow++] = nums[fast++];
        }else {
            fast++;
        }
    }

    while(slow < numsSize) {
        nums[slow++] = 0;
    }
    return;
}
```