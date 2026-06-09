### 解题思路
使用大小号标记 small表示<  large表示> , 当出现连续两次small或者large，那么更新一次最大值；
注意两个细节，count= A[i-1]==A[i] ? 1:2  以及最后返回的应该是Math.max(re, count)，而不是re.
时间复杂度O(n)

### 代码

```java
class Solution {
    public int maxTurbulenceSize(int[] A) {
        // 连续出现两个< < 或者> >，那么就需要以当前索引重新计算。
        if (A.length <2) {
            return A.length;
        }
        int small=-1, large=-1, re=1, count=1;
        for (int i=1; i<A.length; i++) {
            if (A[i-1] < A[i] && (small == -1)) {
                small = 1;
                large = -1;
                count++;
            } else if (A[i-1] > A[i] && (large == -1)) {
                large = 1;
                small = -1;
                count++;
            } else {
                re = Math.max(re, count);
                // 细节1 
                count= A[i-1]==A[i] ? 1:2;
            }
        }
        // 细节2
        return Math.max(re, count);
    }
}
```