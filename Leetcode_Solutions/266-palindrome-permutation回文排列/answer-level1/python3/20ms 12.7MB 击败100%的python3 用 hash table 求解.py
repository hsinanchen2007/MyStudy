初始化hash table，遍历字符串，如果字母已经成为hash的键，就判断value ==1，等于1则-1，等于0则+1。若键不存在则建立新的键，值为1。
返回结果：当s的length为偶数，hash的值相加为0；当s的length为奇数，hash的值相加为1。

```
def canPermutePalindrome(self, s: str) -> bool:
        if not s:
            return True
        hash = {}
        for e in s:
            if hash.get(e):
                if hash[e] == 1:
                    hash[e] -= 1
                elif hash[e] == 0:
                    hash[e] += 1
            else:
                hash[e] = 1
        return not sum(hash.values()) if len(s) % 2 == 0 else sum(hash.values()) == 1
```

![回文排列.PNG](https://pic.leetcode-cn.com/a5d3b31b1b093f58e8c13aa8260a07a19794d84f1260aed29e66378e4b6eeb76-%E5%9B%9E%E6%96%87%E6%8E%92%E5%88%97.PNG)


