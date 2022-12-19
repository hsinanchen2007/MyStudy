### 解题思路
终于弄懂怕忘记，做了点思路整理。。。
![题解.png](https://pic.leetcode-cn.com/db5e65bdf8fcf3938d9ea98089e9ec72eb6f175225d87382dc8203ec6689b35a-%E9%A2%98%E8%A7%A3.png)


递归写法：
### 代码

```python
class Solution(object):
    def dfs(self,n):
        if n<=0: return 0

        num_s = str(n) 
        high = int(num_s[0])  
        Pow = 10**(len(num_s)-1) 
        last = n - high*Pow
        
        if high == 1:
            return self.dfs(Pow-1)+self.dfs(last)+last+1
        else:
            return Pow+high*self.dfs(Pow-1)+self.dfs(last)


```
这题一般方法运行超时：
```
#运行超时
class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = ''
        while n:
            s += str(n)
            n = n-1
        return s.count('1')
```
参考：
    作者：yuruiyin 
    https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/java-di-gui-qiu-jie-by-npe_tle-2/
