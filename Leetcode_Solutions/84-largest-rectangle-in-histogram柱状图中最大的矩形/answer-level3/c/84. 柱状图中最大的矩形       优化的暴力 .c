### 解题思路
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 



以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。




1. temp_min_heith  为i和 j之间的最低高度，  得到当前面积
2. 内循环， j=i, 遍历j ~ heighSize 找i起始时最大面积;  
3. 外循环， 遍历i ~ heighSize
### 代码

```c
int largestRectangleArea(int* heights, int heightsSize){
    int i,temp_area=0,temp_minh=0,max_area=0,j;

    for(i=0;i<heightsSize;i++){
        temp_minh = heights[i];
        for(j=i;j<heightsSize;j++){
            temp_minh = temp_minh < heights[j] ? temp_minh: heights[j];
            //printf("cyx temminh=%d i=%d j=%d \n",temp_minh,i,j);
            temp_area = temp_minh * (j-i+1);
            max_area = max_area > temp_area ? max_area : temp_area;
        }
    }
    return max_area;
}
```