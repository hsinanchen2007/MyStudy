**题解1**：遇到0以后反向搜索

bool canJump(int* nums, int numsSize) {
    int i, j;
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] > 0) {
            continue;
        }
        
        for (j = i - 1;  j >= 0; j--) {
            if (nums[j] + (j - i) > 0) break;
        }
        if (j < 0) {
            break;
        }
    }
    return (numsSize- 1 == i);
}

**题解2**：贪心算法

bool canJump(int* nums, int numsSize) {
    int lastPos = numsSize - 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] + i >= lastPos) {
            lastPos = i;
        }
    }
    return (lastPos == 0);
}