### 解题思路
一定要用long型，否则溢出，还是python好啊！！！

### 代码

```java
class Solution {
    public boolean isPerfectSquare(int num) {
        if(num == 1) {
            return true;
        }
        long start = 0, end = num / 2;
        while (start + 1 < end) {
            long mid = start + (end - start) / 2;
            if (mid * mid < num) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (start * start == num || end * end == num) {
            return true;
        }
        return false;
    }
}
```