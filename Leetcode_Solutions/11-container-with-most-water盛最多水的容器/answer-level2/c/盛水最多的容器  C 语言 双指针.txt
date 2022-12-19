### 解题思路
![屏幕快照 2020-03-12 下午5.57.32.png](https://pic.leetcode-cn.com/88797c020168f1be07efbbf93998d73136ce63fa71259427cd9a19ed4ab8b192-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-12%20%E4%B8%8B%E5%8D%885.57.32.png)

面积由宽高决定，高度由两侧中较小的决定，宽度是两个元素之间的index差值。

i、j 分别为首位两个元素的下标，这是宽度的最大值，向中间聚拢，每次移动两元素中较小的元素，以期望用宽度的减少，换取高度的增加，进行遍历，并求出面积与当前最大面积进行对比。

### 代码

```c
int maxArea(int* height, int heightSize){
    int i = 0, j = heightSize - 1, max = 0, area = 0, width = 0;
    while (i < j){
        width = j - i;
        if (height[i] <= height[j]){
            area = height[i++] * width;
        }else {
            area = height[j--] * width;
        }
        max = (area > max ? area : max);
    }
    return max;
}
```