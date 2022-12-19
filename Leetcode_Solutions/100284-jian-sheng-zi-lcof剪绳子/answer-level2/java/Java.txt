### 解题思路
拆分后的数[2,3]
如果拆分后有4，4=2*2，还可以拆分为2*2
如果拆分后>=5 3*（n-3）=3n-9>n
所有拆分后只有2，3这三个最优解
最多有2个2，一旦有3个2.那么3*3>2*2*2 ,4个2，2*2*2*2<2*3*3
所有尽可能多的要3
### 代码

```java
class Solution {
    public int cuttingRope(int n) {

        //m>1
        if(n <= 3) return 1 * (n - 1);
        int res = 1;
        if(n % 3 == 1) 
        {
            res *= 4;
             n-= 4;
        }
        if(n % 3 == 2) 
        {
            res *= 2;
            n-= 2;
        }
        while(n > 0)
        {
             res *= 3;
             n -= 3;
        }
        return res; 
    }
}
```