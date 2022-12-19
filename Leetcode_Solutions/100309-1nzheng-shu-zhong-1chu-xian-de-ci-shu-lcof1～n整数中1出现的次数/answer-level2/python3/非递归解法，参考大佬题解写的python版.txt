### 解题思路
#参考题解https://leetcode-cn.com/problems/number-of-digit-one/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-50/
大致思路：
1、找到每一位为1的规律，比如千位为1。
2、先把千位上的数字置1，千位左边可以取多少，千位右边可以取多少
3、这就要分情况了，
当千位的数本来是0，你现在把它置1了，所以左边（高位）上就可以从0取到高位-1，右边就可以取0-999都是满足情况的
当千位本来就是1，则除了千位是0部分还要加上它本来是1增加的部分，就是0到千位后面的数的大小，即千位后面数+1
当千位大于1，则说明当千位为1时，千位后面的数还可以取到0-999共一千个，即加上1000
4、其他位也类似，一位一位的计算
### 代码

```python3
class Solution:
    def countDigitOne(self, n: int) -> int:
        k=1   #计算到哪位了
        count=0
        while k<=n:
            h=n//k   
            l=n%k        #第k位右边的低位
            m=h%10       #第k位的数字
            hh=h//10     #k位左边的高位
            count+=hh*k  #高位*k位是高位变化所得到的
            if m>1:
                count+=k #除了高位变化得到的，还有第k位为1时得到的
            if m==1:
                count+=l+1 #除了高位变化得到的，还有第k位本来是1的到的
            k*=10
        return count
```