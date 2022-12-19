### 解题思路
> 关键要理解的是, 当前格子位置上的雨水量依赖的因素: ```rain[i] = MIN(左边最高值, 右边最高值) - Height[i]``` ; 理解了这个就可以设计算法了; 此处我们用dp方法,空间换时间, 求出每个位置的 两边最高值, 然后一次遍历搞定; 时间复杂度是 O(3N) ~ O(N) ;
- 从左到右, 计算 每个位置的左侧最大值;
- 从右到左, 计算 每个位置的右侧最大值;
- 遍历高度, 计算每个位置可能的雨水量, 累加到结果中;

### 代码

```c [groups1-C]
#define MIN_HEIGHT(a, b) ((a) < (b) ? (a) : (b))

void UpdateLeftMax(int *arr, int *height, int size)
{
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (height[i] > max) {
            max = height[i];
        }
        arr[i] = max;
    }
}

void UpdateRightMax(int *arr, int *height, int size)
{
    int max = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (height[i] > max) {
            max = height[i];
        }
        arr[i] = max;
    }
}

int GetTrap(int *leftMax, int *rightMax, int *height, int size)
{
    UpdateLeftMax(leftMax, height, size);
    UpdateRightMax(rightMax, height, size);
    int ans = 0;
    int smallHeight;
    for (int i = 0; i < size; i++) {
        smallHeight = MIN_HEIGHT(leftMax[i], rightMax[i]);
        if (smallHeight > height[i]) {
            ans += smallHeight - height[i];
        }
    }
    return ans;
}

int trap(int *height, int heightSize)
{
    if (height == NULL || heightSize <= 2) {
        return 0;
    }
    int memSize = sizeof(int) * heightSize;
    int *leftMax = (int *)malloc(memSize);
    if (leftMax == NULL) {
        return 0;
    }
    int *rightMax = (int *)malloc(memSize);
    if (rightMax == NULL) {
        free(leftMax);
        return 0;
    }
    memset(leftMax, 0, memSize);
    memset(rightMax, 0, memSize);
    int ans = GetTrap(leftMax, rightMax, height, heightSize);
    free(leftMax);
    free(rightMax);
    return ans;
}
```

```python3 [groups1-python3]
class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        left_max = [0] * len(height)
        right_max = [0] * len(height)
        curr_max = 0
        for i, n in enumerate(height):
            if n > curr_max:
                curr_max = n
            left_max[i] = curr_max

        curr_max = 0
        for i in range(len(height) - 1, -1, -1):
            if height[i] > curr_max:
                curr_max = height[i]
            right_max[i] = curr_max

        ans = 0
        for i, n in enumerate(height):
            small = min(left_max[i], right_max[i])
            if height[i] < small:
                ans += small - height[i]
        return ans
```

### 运行情况
```
执行用时 :4 ms, 在所有 C 提交中击败了95.63%的用户
内存消耗 :6.2 MB, 在所有 C 提交中击败了100.00%的用户

```