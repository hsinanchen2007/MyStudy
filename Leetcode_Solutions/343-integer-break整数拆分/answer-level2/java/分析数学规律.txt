### 解题思路
2=1+1->1*1=1
3=1+2->1*2=2
4=2+2->2*2=4
5=3+2->3*2=6
6=3+3->3*3=9
7=3+4->3*4=12
8=3+3+2->3*3*2=18
9=3+3+3->3*3*3=27
10=3+3+4->3*3*4=39
......
当数大于3后，可以发现一个规律，
如果数除以3余0，分为n/3个3，可以得到最大值
如果数除以3余1，分为n/3-1个3和一个4，可以得到最大值
如果数除以3余2，分为n/3个3和一个2，可以得到最大值
综上

### 代码

```kotlin
class Solution {
    fun integerBreak(n: Int): Int {
        if (n <= 3) {
            return n - 1
        }
        val num = n / 3
        val r = n % 3
        if (r == 0) {
            return Math.pow(3.toDouble(), num.toDouble()).toInt()
        }
        return if (r == 1) {
            (Math.pow(3.toDouble(), num.toDouble() - 1) * 4).toInt()
        } else {//r==2
            (Math.pow(3.toDouble(), num.toDouble()) * 2).toInt()
        }
    }
}
```

```java
 public int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int num = n / 3;
        int r = n % 3;
        if (r == 0) {
            return (int) Math.pow(3, num);
        }
        if (r == 1) {
            return (int) Math.pow(3, num - 1) * 4;
        } else //r==2
        {
            return (int) Math.pow(3, num) * 2;
        }
    }
```

