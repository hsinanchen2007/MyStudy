### 解题思路
![image.png](https://pic.leetcode-cn.com/f03e6392c2ae8c6c5e5dcae6353b2ba1df451f98add11d06158546c496c1859a-image.png)

把这个题目想象成有2n个格子放快递，使其满足相应的条件

先放第一个格子，有n种情况（因为只能放P），然后算这个P对应的D有几个位置，算出来是(2n-1)
接下来放第二个P，我们把这个P放在距离前一个最近的格子里，那么第二个P有（n-1）种情况，接下来算D的位置，那么D的位置有（2n-3）
。。。
以此类推，将他们都相乘即可n\*(2n-1)\*(n-1)\*(2n-3)....
（其实算到上面就可以发现跟示例1 2 3都满足，规律找到了，接下来写代码即可）

### 代码

```java
class Solution {
    public int countOrders(int n) {
        int cur=0;
        long ans=1;
        int m=n;
        while(--m>0){
            ans=ans*(n-cur)*(2*n-2*cur-1)%1000000007;
            cur++;
        }
        return (int)ans%1000000007;
    }
}
```