### 解题思路
运用了循环的思想
s2字符串相当于从s1的某个位置开始遍历，然后当遍历到s1末尾的时候 就从s1头部开始重新遍历

扫描s1时，可以先比较一下此时的s1[i]，也就是st（存放遍历结果的中间变量）的首个字符是否与s2的首个字符相等：
如果相等，就存在 st 和 s2 相等的可能，循环遍历s1 存入st， 然后比较st和s2是否相等
如果不相等的话，就可以直接移动到s1的下一个元素了。

### 代码

```python
class Solution(object):
    def isFlipedString(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if not s1 and not s2 : return True
        if len(s1) != len(s2) : return False
        for i in range(0, len(s1)) :
            if s1[i] == s2[0] :
                st = s1[i :]+ s1[0 : i % len(s1)]
            # print st
                if st == s2 : return True 
        return False

```
![轮转字符串.gif](https://pic.leetcode-cn.com/e03ddfac7b021e45386625c9862756803c0006c1309384fe37f011e29d497e46-%E8%BD%AE%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.gif)

