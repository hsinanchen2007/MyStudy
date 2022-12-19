思路：
盛最多水，决定于高度较小一边；
遍历所有两边求出面积，得出最大值
```
int MoreSmall(int a, int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}
int maxArea(int* height, int heightSize) {
    if (heightSize < 2) {
        return 0;
    }
    int i, j;
    long long first_water = MoreSmall(height[0], height[1]);
    for (i = 0; i < heightSize-1; i++) {
        for (j = i+1; j < heightSize; j++) {
            int smallerHeight = MoreSmall(height[i], height[j]);
            long long water = (j-i) * smallerHeight;
            if (water >= first_water) {
                first_water = water;
            }
        }
        
    }
    return first_water;
}
```
