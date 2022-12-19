### 解题思路
O(N) 左右边界 i j 向中间收敛
如果采取暴力解法，枚举所有情况，两层嵌套循环实现 O（N^2)

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        for(int i = 0,j = height.length-1;i < j;) {
            int minHeight = height[i] < height[j] ? height[i++] : height[j--];
            int area = minHeight * (j - i + 1);
            max = Math.max(area,max);
        }
        return max;
    }
}
```