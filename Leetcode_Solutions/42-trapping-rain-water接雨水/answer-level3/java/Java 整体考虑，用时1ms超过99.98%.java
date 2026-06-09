### 解题思路
**整体思路**
柱子和装满雨水后组成的整体面积，减去柱子自身的面积；
**柱子自身的面积**
数组元素直接累加求和即可，顺便得到最大值及其对应的索引；
**柱子和雨水组成形状的面积**
考虑装满雨水之后的样子，雨水将其中所有的坑都填满；
这时无论是从左往右，还是从右往左，到达峰值前必然都是非递减的（因为坑被雨水填满了）；
故在知道全局最大值的情况下，只需从两端向中间累加当前遇到元素中的最大值即可。

### 代码

```java
class Solution {
    public int trap(int[] height) {
        if(height.length == 0)
            return 0;
        
        // 求柱子组成的形状的总和，顺便求出最大值及其位置
        int mIndex = 0, max = 0, sum = 0;
        for(int i = 0; i < height.length; i ++){
            sum += height[i];
            if(max < height[i]){
                max = height[i];
                mIndex = i;
            }
        }
        
        // 计算雨水和柱子组成的形状的总和
        int total = height[mIndex];
        int currMax = 0;
        for(int i = 0; i < mIndex; i ++){
            currMax = Math.max(currMax, height[i]);
            total += currMax;
        }
        currMax = 0;
        for(int i = height.length - 1; i > mIndex; i --){
            currMax = Math.max(currMax, height[i]);
            total += currMax;
        }

        // 雨水和柱子形状和 - 柱子自身的和
        return total - sum;
    }
}
```