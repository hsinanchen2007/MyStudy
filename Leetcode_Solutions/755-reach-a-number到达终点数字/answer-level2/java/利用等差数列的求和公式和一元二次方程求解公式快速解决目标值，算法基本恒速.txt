### 解题思路
利用等差数列的求和公式和一元二次方程求解公式快速解决目标值，算法基本恒速

### 代码

```java
class Solution {
    public int reachNumber(int target) {
        //等差数列的求和公式Sn=n(a1+an)/2
        //一元二次方程求解公式 
        // 利用求解公式快速接近目标值。
        target=Math.abs(target);
        int n =  (int)(Math.sqrt(2*target));
        int sum=(n*(1+n)/2);
        //n%2==0 则和位奇数，n%2==1则和也为计数
        while (sum<target){
            n++;
            sum+=n;
            
        }
        return (target-sum)%2==0 ? n : n + 1 + n%2;
    }
}
```