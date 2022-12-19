## 题目描述

>你的面前有一堵方形的、由多行砖块组成的砖墙。 这些砖块高度相同但是宽度不同。你现在要画一条自顶向下的、穿过最少砖块的垂线。
砖墙由行的列表表示。 每一行都是一个代表从左至右每块砖的宽度的整数列表。
如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。你需要找出怎样画才能使这条线穿过的砖块数量最少，并且返回穿过的砖块数量。
**你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。**

## 示例

输入: 
```[[1,2,2,1],
      [3,1,2],
      [1,3,2],
      [2,4],
      [3,1,2],
      [1,3,1,1]]
```

输出: ```2```
![image.png](https://pic.leetcode-cn.com/cfa25bbaa6f01819a9e789061a11a0d99a46364f0450aef4b0c4d49c23933696-image.png)

## 思路
我们可以看一下上面的示意图，把它当成一个平面直角坐标系，每一行第一块砖的`左边界`贴在`y`轴上，也就是`x = 0`,我们需要找到一条直线`x = k`,使得`右边界`贴在这条线上的砖最多，那么我们只需要统计每一块砖的`右边界`对应的直线，数量最多的就是我们需要的，而计算每一块砖的右边界，其实就是一个`前缀和`，所以我们用一个变量`sum`去维护每一行的`前缀和`，然后再用一个`map`做统计就可以了。
注意：`x = 0`和`右边缘`不能算。

## 代码

```java
class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        Map<Integer, Integer> preFixSumCount = new HashMap<>();
        int maxCount = 0;
        for (List<Integer> list: wall) {
            int sum = 0;
            for (int i = 0; i < list.size() - 1; i++) {
                sum += list.get(i);
                int count = preFixSumCount.getOrDefault(sum, 0) + 1;
                preFixSumCount.put(sum, count);
                maxCount = Math.max(maxCount, count);
            }
        }
        return wall.size() - maxCount;
    }
}
```