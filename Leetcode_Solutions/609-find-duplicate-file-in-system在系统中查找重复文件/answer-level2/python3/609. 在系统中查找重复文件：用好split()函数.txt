![image.png](https://pic.leetcode-cn.com/2ac0fe68aea7d1b180fd88af306bde1041624abde2ad0bd18347f68a7ad06bef-image.png)


108ms，100%。

就是切割再切割，切完装进字典，最后筛出来。

```python []
class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        d = collections.defaultdict(list)
        for path in paths:
            doc = path.split(' ')   #按空格切割字符串，首元素为路径
            for file in doc[1: ]:
                name, content = file.split('(')   #按左括号切割字符串，补完路径和找到字符串的key
                d[content] += [doc[0] + '/' + name]
        return filter(lambda s: len(s) > 1, d.values())
```

对于大文件可以考虑`hash(content)`或者其他通用的`hash`方法，可以减少字典的内存消耗。

![image.png](https://pic.leetcode-cn.com/33ef31392a51271d786be2e70ed94c09b12e92c9dcea1ce70465930fd32e3275-image.png)

```python []
class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        d = collections.defaultdict(list)
        for path in paths:
            doc = path.split(' ')
            for file in doc[1: ]:
                name, content = file.split('(')
                d[hash(content)] += [doc[0] + '/' + name] #此处hash
        return filter(lambda s: len(s) > 1, d.values())
```
