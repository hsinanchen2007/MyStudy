### 解题思路
此处撰写解题思路

### 代码

```c
int jump(int* nums, int numsSize){
    if (nums == NULL || numsSize < 1) {
        return 0;
    }
    if (numsSize ==  1) {
        return 0;
    }
    int reach = 0;
    int nextreach = nums[0];
    int step = 0;
    for (int i = 0; i < numsSize; i++) {
        nextreach = (nums[i] + i) > nextreach ? (nums[i] + i) : nextreach;
        if (nextreach >= numsSize - 1) {
            return step+1;
        }
        if (i == reach) {
            step++;
            reach = nextreach;
        }
    }
    return step;
}
```