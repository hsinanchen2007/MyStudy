### 解题思路
本题需要找到最大的三个数，并同时满足其中较小的两个数之和大于最大数（三角形必须满足任意两边之和大于第三边）。将数组升序排序，尽可能地选排最后的连续三个数（为了周长最大化），一旦满足较小两数之和大于最大数，这三个数就是答案。
时间复杂度：O(nlogn)。用于排序。
空间复杂度：O(1)。

### 代码

```java
class Solution {
    public int largestPerimeter(int[] A) {
        Arrays.sort(A);
        for(int i=A.length-3;i>=0;i--)
        {
            if(A[i]+A[i+1]>A[i+2])
                return A[i]+A[i+1]+A[i+2];
        }
        return 0;
    }
}
```