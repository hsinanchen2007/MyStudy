### 解题思路
1. 首先选取首尾两根柱子作为开始基准，依次将选取位置向中间靠拢
2. 若左边柱子高度小于右边柱子高度，则将左边柱子向右靠拢一位，反之，将右边柱子向左靠拢一位
3. 求出面积，循环求得最大值
### 代码

```java
class Solution {
    public int maxArea(int[] a){
        int max = 0;
        for (int i = 0, j = a.length -1; i < j; ) {
            int minHeight = a[i] < a[j] ? a[i ++] : a[j --];
            int area = (j - i + 1) * minHeight;
            max = Math.max(max, area);
        }
        return max;
    }
}
```