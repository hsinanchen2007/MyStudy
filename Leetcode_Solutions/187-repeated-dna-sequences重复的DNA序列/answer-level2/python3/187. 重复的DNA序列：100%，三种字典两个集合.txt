
布尔字典：

![image.png](https://pic.leetcode-cn.com/df20734ed78ce76f6de40acd3f0a1a3ef54c36e24575157636a01124195510f8-image.png)

```python []
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        d = {}
        for i in range(len(s) - 9):
            if s[i: i + 10] in d:
                d[s[i: i + 10]] = True
            else:
                d[s[i: i + 10]] = False
        return filter(lambda i: d[i], d)
```

计数字典：

![image.png](https://pic.leetcode-cn.com/396b86fd0ac67b2d37dbbfce02d8eee1f2d080b7ec11ca88699d49ed7f2253c4-image.png)

```python []
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        d = collections.Counter(s[i: i + 10] for i in range(len(s) - 9))
        return filter(lambda i: d[i] > 1, d)
```

整型字典：

![image.png](https://pic.leetcode-cn.com/68534969af686454004aa43acb1897dbcf8a2fee285288fa6a1e19872859324e-image.png)

```python []
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        d = collections.defaultdict(int)
        for i in range(len(s) - 9):
            d[s[i: i + 10]] += 1
        return [i for i in d if d[i] > 1]
```

两个集合：

![image.png](https://pic.leetcode-cn.com/d2e45555f0505f88c9f336779a68ce9461c3f8c985fedf1c3ba3524e34979668-image.png)

```python []
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        tmp, ans = set(), set()
        for i in range(len(s) - 9):
            if s[i: i + 10] not in tmp:
                tmp.add(s[i: i + 10])
            elif s[i:i + 10] not in ans:
                ans.add(s[i: i + 10])
        return list(ans)
```
