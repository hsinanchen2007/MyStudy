### 解题思路
双指针法，矩形的面积取决于两边的短板。
宽则是（right - left）
每次进行移动，丢弃短边。
需要注意的是，计算面积的时候，长是两边较短的那一边

### 代码

```c
int maxArea(int* height, int heightSize){
    if (height == NULL || heightSize == 0) {
        return 0;
    }

    if (heightSize == 1) {
        return height[0];
    }

    int left = 0;
    int right = heightSize - 1;
    int max = 0;

    while(left < right) {
        if (height[left] < height[right]) {
            int newMax = height[left] * (right - left);
            max = max >= newMax ? max : newMax;
            left++;
        }else {
            int newMax = height[right] * (right - left);
            max = max >= newMax ? max : newMax;
            right--;
        }
    }
    return max;
}
```