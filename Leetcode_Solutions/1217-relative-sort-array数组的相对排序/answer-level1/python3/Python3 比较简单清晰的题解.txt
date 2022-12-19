```
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        res = []
        li = []
        for y in arr2:
            for x in arr1:
                if x == y:
                    res.append(x)
        for i in arr1:
            if i not in res:
                li.append(i)
        return res + sorted(li)
```
![image.png](https://pic.leetcode-cn.com/f17ea0de4d0421d1d5a9ed08ec36570a0346ce938368fdb9c68e62e91f52526a-image.png)

是一只正在学习的小白啦，所以代码显得繁复一些啦~以后会越来越精简的