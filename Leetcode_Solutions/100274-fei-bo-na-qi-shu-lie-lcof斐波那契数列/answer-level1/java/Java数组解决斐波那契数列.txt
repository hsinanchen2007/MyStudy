### 解题思路
声明一个长度为3数组，存放斐波那契数列的三项。
将数组当成一个环，每次所求的项在数列中的下标为循环数模3。
剩余两项的下表分别为（循环数+1）模3，（循环数+2）模3。

### 代码

```java
class Solution {
    public int fib(int n) {
        int[] fArr = {0,1,0};
        for(int i = 2; i <= n; i++){
            fArr[i%3] = (fArr[(i+1)%3] + fArr[(i+2)%3])%1000000007;
        }
        return fArr[n%3];
    }
}
```