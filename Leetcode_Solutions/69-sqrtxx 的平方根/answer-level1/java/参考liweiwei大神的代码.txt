### 解题思路
利用Integer的最大值进行二分查找

### 代码

```java
class Solution {

    public int mySqrt(int x) {
        //二分查找的思路
        long left   =  0;
        long right  =  Integer.MAX_VALUE;
        
        //int 类型开始二分查找
        while (left < right) {
            long mid = (left + right + 1) >>> 1;//无符号右移位

            long square = mid*mid;

            if (square > x) {
                right = mid - 1;
            } else {
                left  = mid;
            }
        }

        //返回的值
        return (int)left;
    }
}
```