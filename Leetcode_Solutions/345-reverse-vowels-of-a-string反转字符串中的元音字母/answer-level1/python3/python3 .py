### 解题思路
这题可以使用双指针来解决
具体做法：一个指针从头向尾遍历，另一个指针从尾到头遍历，当两个指针都遍历到元音字符时，交换这两个元音字符的位置。
示意图如下，来源 https://github.com/CyC2018/CS-Notes/blob/master/notes/Leetcode%20%E9%A2%98%E8%A7%A3%20-%20%E5%8F%8C%E6%8C%87%E9%92%88.md
![68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f65663235666637632d306636332d343230642d386233302d6561666265656133356431312e676966.gif](https://pic.leetcode-cn.com/2bd7909f241a77cbc1b1842cc089c0ddec63c9a29ae4a5c5c7a3736820ed62aa-68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f65663235666637632d306636332d343230642d386233302d6561666265656133356431312e676966.gif)

注意点：
1、新建一个s的副本，并转换为list类型。这是因为str类型不可变数据类型，因此转换为list类型。

### 代码

```python
class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        result=list(s)
        vowels= ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        i, j=0, len(s)-1
        while i<j:
            if result[i] not in vowels:
                i += 1
            elif result[j] not in vowels:
                j -= 1
            else:
                result[i],result[j]=result[j],result[i]
                i += 1
                j -= 1
        return ''.join(result)
```