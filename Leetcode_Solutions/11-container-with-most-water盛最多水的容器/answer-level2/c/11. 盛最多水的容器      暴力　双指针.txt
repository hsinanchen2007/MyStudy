### 解题思路
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。




### 代码

```c
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int maxArea(int* height, int heightSize){
    
#if 0
    int i, j;
    int area, max = 0;
    for (i = 0; i < heightSize; i++) {
        for (j = i + 1; j < heightSize; j++) {
            area = (j - i)*MIN(height[i], height[j]);
            max = MAX(max, area);
        }
    }
#else
    int i = 0, j = heightSize - 1;
    int area, max = 0;

    while (j > i) {
        area = (j - i) * MIN(height[i],height[j]);
        max = MAX(area, max);
        if (height[i] > height[j])      //两边哪个墙低就哪边变动
            j--;
        else
            i++;
    }

#endif
    return max;
}
```