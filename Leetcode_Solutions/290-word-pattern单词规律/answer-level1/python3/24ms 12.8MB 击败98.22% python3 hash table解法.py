初始化hash table，将string str split成列表s。
首先排除s和pattern的长度不相等时，直接return false。这是为解决pattern与str的数量不同的特殊情况。如：
`pattern："aaa"
str："aa aa aa aa"`
先用enumerate（）将pattern转化。
判断v是否已经成为hash的键：
    1.若不是则先判断单词s[k]是否已经储存在hash里面：
        1）是则return false；
        2）否，则生成hash[v] = s[k],k为pattern的索引值；
    2.若v是hash的键，则当hash[v] != s[k],return false。
若以上情况均已排除，return true。

```
def wordPattern(self, pattern: str, str: str) -> bool:
        hash = {}
        s = str.split()
        if len(pattern) != len(s):
            return False
        for k, v in enumerate(pattern):
            if hash.get(v):
                if hash[v] != s[k]:
                    return False
            else:
                if s[k] in hash.values():
                    return False
                hash[v] = s[k]
        return True
```

![单词规律.PNG](https://pic.leetcode-cn.com/cc9d29034a732fb08ddffd2ec6fbf6e505ebacc908c2a4f07dedb2b480b5df7f-%E5%8D%95%E8%AF%8D%E8%A7%84%E5%BE%8B.PNG)

