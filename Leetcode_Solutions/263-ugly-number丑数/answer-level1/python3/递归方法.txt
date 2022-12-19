### 解题思路
![QQ浏览器截图20191214171134.png](https://pic.leetcode-cn.com/89104d67a1dc1983b9272906505e78cd5aaa17aa5bcd4eea12616b446dc62c2c-QQ%E6%B5%8F%E8%A7%88%E5%99%A8%E6%88%AA%E5%9B%BE20191214171134.png)
对数字进行判断，如果可以整除2,3,5则将数字进行更新，更新为num除以2或3或5的商，然后进行递归调用。如果不可以，则返回FALSE。

### 代码

```python3
class Solution:
    def isUgly(self, num: int) -> bool:
        if num==1:
            return True
        elif num==0:
            return False
        else:
            if num%2==0:
                num=num/2
                return self.isUgly(num)
            elif num%3==0:
                num=num/3
                return self.isUgly(num)
            elif num%5==0:
                num=num/5
                return self.isUgly(num)
            else:
                return False
```