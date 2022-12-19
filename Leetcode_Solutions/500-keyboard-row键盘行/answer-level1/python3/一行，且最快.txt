标题中的一行是指 本算法在某种意义上在findWords函数体内的语句仅有一行。
标题中的最快是指 此前所有Python3解答最短用时24ms，本算法仅用20ms。
```python
class Solution:
    f = [1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2]
    def findWords(self, words: List[str]) -> List[str]:
        def helper(word):
            i = Solution.f[ord(word[0])-97]
            return all(Solution.f[ord(char)-97]==i for char in word[1:])
        return [word for word in words if helper(word.lower())]
```
![image.png](https://pic.leetcode-cn.com/0bf6f8ec8223181248b45da6e26a226f85b04b5d557032dd1b7171b067b2f404-image.png)
