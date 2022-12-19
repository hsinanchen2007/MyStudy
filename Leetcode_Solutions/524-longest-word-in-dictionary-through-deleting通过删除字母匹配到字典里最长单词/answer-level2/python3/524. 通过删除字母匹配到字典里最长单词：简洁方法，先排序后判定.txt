用好系统函数sort()和find()就行，详见注释。

![image.png](https://pic.leetcode-cn.com/8671538b0233d950d48569568479ef8c2374b72e212d0b66b23edac080087a15-image.png)

```python []
class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        d.sort(key = lambda x: [-len(x), x])#对字典d进行排序，第一关键字是长度升序，第二关键字是字符串本身字典序
        def f(c):                   #匹配函数
            i = 0
            for j in c:             #遍历单词里的字母
                k = s.find(j, i)    #查找函数，后一个参数是查找起点
                if k == -1:
                    return False    #查找失败就返回错误
                i = k + 1           #查找成功就更新查找起点
            return True
        for c in d:                 #遍历有序字典里的单词
            if f(c):                #如果匹配就返回单词
                return c
        return ''
```
```python []
class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        d.sort(key = lambda x: (-len(x), x))
        def f(c):
            i = 0
            for j in c:
                k = s.find(j, i)
                if k == -1:
                    return False
                i = k + 1
            return True
        return next((c for c in d if f(c)), '')
```
