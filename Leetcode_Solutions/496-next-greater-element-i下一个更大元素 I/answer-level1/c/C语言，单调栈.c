### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NUM 10000
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *stack = calloc(MAX_NUM, sizeof(int));/* 模拟栈 */
    int *map = calloc(MAX_NUM, sizeof(int)); /* 映射表 */
    int top = -1; /* 栈顶 */
      
    for (int i = 0; i < nums2Size; i++) {
        //if (nums2[i] >= MAX_NUM) { // 如果哈希表容量小于所需大小，重新分配空间
        //   int size = nums2[i] + 100;
        //   map = realloc(map, size * sizeof(int));
        //}
        while (top > -1 && nums2[i] > stack[top]) {
            map[stack[top]] = nums2[i];
            top--;
        } 
        stack[++top] = nums2[i];        
    }

    while (top >= 0) {
        map[stack[top--]] = -1;
    }

    int *result = calloc(nums1Size, sizeof(int));
    for (int j = 0; j < nums1Size; j++) {
        result[j] = map[nums1[j]];
    }
    free(stack);
    free(map);
    *returnSize = nums1Size;
    return result;
}
```