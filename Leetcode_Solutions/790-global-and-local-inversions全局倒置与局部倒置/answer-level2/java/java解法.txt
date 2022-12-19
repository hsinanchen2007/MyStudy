首先需要明白如果一个倒置是局部倒置，那它一定是全局倒置，但是反之则不然，所以我们要做的事情很简单，只需要判断相隔至少一个位置距离的时候前面的数字是否存在大于后面的数字的情况即可。
```java
class Solution {
    public boolean isIdealPermutation(int[] A) {
        int len = A.length;
        if (len <= 2) {
            return true;
        }
        int max = A[0];
        for (int i = 2; i < len; i ++) {
            if (max > A[i]) {
                return false;
            }
            if (max < A[i - 1]) {
                max = A[i - 1];
            }
        }
        return true;
    }
}
```
