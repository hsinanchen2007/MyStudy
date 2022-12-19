### 解题思路
先用二分查找找到target的其中一个位置，然后平移指针，找出左边界和右边界
平移指针时，确保指针左右两边还有数，否则会导致访问越界
左移时，确保mid左边还有数(mid > 0);
右移时，确保mid右边还有数(mid < numsSize - 1)
时间复杂度：O(logn); 空间复杂度:O(1)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>  // malloc
#include <string.h>  // memset 
#define N 2
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    // 初始化返回数组position
    int* position = (int*)malloc(N * sizeof(int));
    memset(position, 0, N * sizeof(int));
    position[0] = -1;
    position[1] = -1;
    *returnSize = N;    // 返回数组长度为2
    
    // 处理异常情况
    if (nums == NULL || numsSize < 1 || target < nums[0] || target > nums[numsSize - 1]) {
        return position;
    }
    
    // 按数组升序用二分查找，求得position[0]
    // 如果找到target，position[0]更新为mid；
    // 如果结束while，依然没找到target，那么position[0]将保持为 -1
    // 如果target > nums[mid], left = mid,倾向于找左边； 如果target > nums[mid], left = mid + 1,倾向于找右边
    int left = 0;
    int right = numsSize - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (target == nums[mid]) {
            position[0] = mid;
            position[1] = mid;
            break;
        } else if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    // 根据中心位置，进行平移
    // 左移时，确保mid左边还有数(mid > 0)
    while (mid > 0 && nums[mid - 1] == target) {
        position[0]--;
        mid--;
    }
    
    // 右移时，确保mid右边还有数(mid < numsSize - 1)
    mid = position[1];
    while (mid < numsSize - 1 && nums[mid + 1] == target) {
        position[1]++;
        mid++;
    }
        
    return position;
}