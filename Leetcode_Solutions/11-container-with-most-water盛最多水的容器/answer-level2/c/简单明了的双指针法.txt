### 解题思路
双指针法左右逼近，寻找最优解

### 代码

```c
int maxArea(int* height, int heightSize){
    int maxarea = 0;
    int left = 0;
    int right = heightSize - 1;
    int w, h, area;
    while (left < right) {
        w = right - left; 
        h = height[left];
        if (height[left] < height[right]) {
            ++left;
        }
        else if (height[left] > height[right]) {
            h = height[right];
            --right;
        }
        else {
            ++left; --right;
        }
        area = w * h;
        if (area > maxarea) maxarea = area;
    }
    return maxarea;
} 
```