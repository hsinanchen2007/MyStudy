### 解题思路
看到这个题，想到了当时滴滴远程面试时让我求根号2的题。
二分法(数据结构没有学好，应该是叫这个名吧~)查找目标值。
要考虑int的最大范围

### 代码

```java
class Solution {
    public int  mySqrt(int x) {

        if (x <= 0) {
            return 0;
        }

        if (x == 1) {
            return 1;
        }
        if(x>=Integer.MAX_VALUE){
            return 46340;
        }
        double result = binarySearch(0, x+1, x);

        return (int) result;
    }

    private static double binarySearch(double left, double right, int x) {

        double mid = (left + right) / 2;
        if(left>=right){
            return mid;
        }
        if (x <= mid * mid && mid * mid < x + 0.001) {
            return mid;
        }

        if (x < mid * mid) {
            return binarySearch(left, mid, x);
        }
        if (x > mid * mid) {
            return binarySearch(mid, right, x);
        }

        return 0;
    }

}
```