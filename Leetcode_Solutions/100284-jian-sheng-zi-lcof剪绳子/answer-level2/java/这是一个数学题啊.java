### 解题思路
其实是个数学题：
```
2*2   > 1*3

2*2*1 < 2*3
2*2*2 < 3*3
```
         if (n==1 || n==2)
            return 1;
        if (n==3)
            return 2;
所以当**n>4**的时候：分出来3与结果集相乘。
当**n<=4**的时候：可以从前置条件中看出n的任何分配方式都要小于等于其本身，所以，就直接乘以结果集就可以了。。

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
         if (n==1 || n==2)
            return 1;
        if (n==3)
            return 2;
        int sum=1;
        while (n>4){
            sum*=3;
            n-=3;
        }
        return sum*n;
    }
}
```