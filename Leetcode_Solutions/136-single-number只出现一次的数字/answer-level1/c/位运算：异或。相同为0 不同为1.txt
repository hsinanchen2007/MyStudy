### 解题思路
此处撰写解题思路

### 代码

```c
int singleNumber(int* nums, int numsSize){
    int tmp = 0;
    for(int i = 0; i < numsSize; i++) {
        tmp ^= nums[i];
    }
    return tmp;
}
```