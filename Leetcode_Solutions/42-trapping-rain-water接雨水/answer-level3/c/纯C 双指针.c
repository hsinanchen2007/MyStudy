### 解题思路
双指针

### 代码

```c
int trap(int* height, int heightSize){
    if (NULL == height || 0 == heightSize)
    {
        return 0;
    }

    int max = 0;
    int leftMax = 0;
    int rightMax = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right)
    {
        leftMax = height[left] > leftMax ? height[left] : leftMax;
        rightMax = height[right] > rightMax ? height[right] : rightMax;

        if (leftMax < rightMax)
        {
            max += leftMax - height[left];
            left++;
        }
        else if (leftMax >= rightMax)
        {
            max += rightMax - height[right];
            right--;
        }
    }

    return max;
}
```