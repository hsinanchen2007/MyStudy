### 解题思路

B[i] = a[i] 左边的 * a[i] 右边的，两个循环分别乘就可以了。

### 代码

```java
class Solution {
    public int[] constructArr(int[] a) {
        int[] res = new int[a.length];
        for (int i = 0; i < res.length; i++) {
            res[i] = 1;
        }
        int left = 1;
        for (int i = 0; i < a.length; i++) {
            res[i] *= left;
            left *= a[i];
        }
        int right = 1;
        for (int i = a.length - 1; i >= 0; i--) {
            res[i] *= right;
            right *= a[i];
        }
        return res;
    }
}
```