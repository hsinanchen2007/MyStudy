### 解题思路
双指针遍历
![image.png](https://pic.leetcode-cn.com/6c687b6a7c909d48bd7d1cf8b766a75b80e58cd03fa7c293106f9831d5c8b81d-image.png)


### 代码

```c
int trap(int* height, int heightSize) {
    int capacity;   /* 雨水容量 */
    int i, j;       /* 双指针 */
    int left_max, right_max;

    if (height == NULL || heightSize < 3) {
        return 0;
    } 
    i = 0;
    j = heightSize - 1;
    left_max = height[i];
    right_max = height[j];
    capacity = 0;

    while (i < j) {
        if (left_max < right_max) {
            while (height[i] <= left_max && i < j) {
                capacity += left_max - height[i];
                ++i;
            }
            left_max = height[i];
        } else {
            while (height[j] <= right_max && i < j) {
                capacity += right_max - height[j];
                --j;
            }
            right_max = height[j];
        }
    }
    return capacity;
}
```