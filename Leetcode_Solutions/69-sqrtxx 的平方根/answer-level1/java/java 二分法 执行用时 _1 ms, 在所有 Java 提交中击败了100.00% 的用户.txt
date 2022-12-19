```java
class Solution {
    public int mySqrt(int x) {
        // 0 不能作被除数
        if (x == 1) {
            return x;
        }
        // left, right, middle
        int left = 0;
        int right = x;
        int middle = x / 2;
        // 二分法
        while (left < right) {
            if (left + 1 == right || left == right) {
                break;
            }
            if (x / middle <= middle) {
                left = x / middle;
                right = middle;
                middle = (left + right) / 2;
            }
            else {
                left = middle;
                right = x / middle;
                middle = (left + right) / 2;
            }
        }
        // 返回
        return right != 0 && x / right == right ? right : left;
    }
}
```