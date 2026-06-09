自己的解法：构造两个字典，在比较
```
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        d_list1 = {}
        d_list2 = {}

        for key,value in enumerate(list1):
            d_list1[value] = key
        for key,value in enumerate(list2):
            d_list2[value] = key
        t = set(list1) & set(list2)
        l = [None,]
        s = 3000
        for i in t:
            m = d_list1[i] + d_list2[i]
            if m < s:
                l.clear()
                l.append(i)
                s = min(m,s)
            elif m == s and i not in l:
                l.append(i)
        return l
```
引用题解区一位大佬的解法
```
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        d = {x: list1.index(x) + list2.index(x) for x in set(list1) & set(list2)}
        return [x for x in d if d[x] == min(d.values())]
使用字典记录｛共同喜欢的商店：索引和｝，返回索引和并列最小的商店名

不知道为什么思路一样，却不能写出像大佬一样优美的代码(⊙o⊙)
```


