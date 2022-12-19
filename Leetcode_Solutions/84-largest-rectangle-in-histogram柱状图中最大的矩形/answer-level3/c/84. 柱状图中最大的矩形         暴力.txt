### 解题思路
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

### 代码

```c
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int largestRectangleArea(int* heights, int heightsSize){
    int i,j;
    int area, max = 0, min;

    //if (heightsSize == 1)
      //  return heights[0];

    for (i = 0;i < heightsSize; i++) {
        min = heights[i];
        for (j = i; j < heightsSize; j++) {
            min = MIN(min, heights[j]);
            area = min * (j - i + 1);
            max = MAX(max, area);
        }
    }
    return max;
}
```