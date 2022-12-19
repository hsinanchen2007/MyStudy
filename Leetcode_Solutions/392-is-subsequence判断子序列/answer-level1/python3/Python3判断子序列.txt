先上代码：
```
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        for i in s:
            if i not in t:
                return False
            t=t.split(i,1)[1]
        return True
```
先看看`s`中每个字符是否在`t`中，如果不在那直接`False`了。然后在`t`中以字符`s`为界限删掉包含此字符的所有前面的字符，更新字符串`t`，重复此过程直到遍历完`s`。
![QQ截图20191118152115.png](https://pic.leetcode-cn.com/459f26c39bf6ec04a5567bdeda988fa7d4bbd78d0ce06bb4dc5d78f5c248cc30-QQ%E6%88%AA%E5%9B%BE20191118152115.png)
