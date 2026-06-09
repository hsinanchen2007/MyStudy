### 解题思路
1.数组内较长的边构成的三角形的周长最长
2.取最长边为c，则需要寻找数据内是否存在边a,b，并且符合条件a+b>c,若存在则为最大周长
### 代码

```java
class Solution {
    public int largestPerimeter(int[] A) {
         if (A.length < 3) {
            return 0;
        }
        Arrays.sort(A);
        for (int i= A.length-1 ; i>=2;i--){
            if (A[i-1] + A[i-2] > A[i]){
                return A[i-1] + A[i-2] + A[i];
            }
        }
        return 0;
    }
}
```

时间复杂度：O(n)
空间复杂度：O(1)