### 解题思路
参考下面的链接
https://leetcode-cn.com/problems/bulb-switcher/solution/wei-shi-yao-ping-fang-shu-yi-ding-shi-liang-zhao-d/278601

链接的内容如下：
对于数k，第i轮被拨一下的条件是k%i==0
所有数k被拨的次数是k的约束的个数
若k=p_1^x p_2^y p_3^z ... , 其中p_i为素数，则约数的个数f(k)= (1+x)(1+y)(1+z).
第k个灯亮意味着f(k)为奇数，根据推论3可知，其中的x,y,z...都必须为耦数。
回看，k=p_1^x p_2^y p_3^z ... , 说明k是个完全平方数


### 代码

```java
class Solution {
    public int bulbSwitch(int n) {
        int res = 0;
        int cur = 1;
        while(cur * cur <= n){
            res++;
            cur++;
        }
        return res;
    }
}
```