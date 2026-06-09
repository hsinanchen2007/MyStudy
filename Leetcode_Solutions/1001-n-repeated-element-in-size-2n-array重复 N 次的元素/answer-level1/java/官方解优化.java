官方要比较的是相邻四个元素。但是由于重复数字m占据2N长度的一半，所以可以分为以下几种情况并进行简化：
1. 重复数字和非重复元素交叉，如\[m,a,m,b,m,c,...\]，或者\[a,m,b,m,c,m,...\]
2. 重复数字和非重复元素不完全交叉，则至少会出现一个地方出现\[...,m,m,...]的相邻情况；
3. 考虑上述两种情况之外的特例。由于官方设定2N>=4。我们在边界条件处发现，如果2N=4的时候，\[m,a,b,m\]仍然符合要求；但是2N>4时，完全可以考虑在上述两种情况中。
基于上述三种情况考虑，可以简化官方Java解如下：
```java []
class Solution {
    public int repeatedNTimes(int[] A) {
        if (A.length == 4 && A[0]==A[3]) {
            return A[0];
        }
        int prepre = A[0];
        int pre = A[1];
        for (int i=2; i<A.length; i++) {
            if (prepre == pre || pre == A[i]) {
                return pre;
            } else if (prepre == A[i]) {
                return prepre;
            } else {
                prepre = pre;
                pre = A[i];
            }
        }
        return -1;
    }
}
```
