### 解题思路

牛顿迭代法是解非线性方程的常见数值解法。计算机使用牛顿迭代法计算一定可以得到二阶收敛的近似解。将近似解和近似解取整后比较，如果相差为0，则说明是完全平方数。**牛顿法收敛最快！！！！**
![微信图片_20200203201031.jpg](https://pic.leetcode-cn.com/44c0d468a2b142e97eccb98f7be3d04928ec728a5288feafb936640346b7c993-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200203201031.jpg)



### 代码

```java
class Solution {
    public boolean isPerfectSquare(int num) {
        float cur=num;
        float next=cur/2+(num/(2*cur));
        while(cur!=next)
        {
            cur=next;
            next=cur/2+(num/(2*cur));
        }
        return cur-(int)cur==0f;
    }
}
```