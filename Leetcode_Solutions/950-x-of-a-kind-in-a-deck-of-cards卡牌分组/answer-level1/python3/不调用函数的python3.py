看python3的解法用了很多函数，不会用函数的菜鸡只能自己写函数
```
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        dic = {}
        for i in range(len(deck)):
            if deck[i] in dic:
                dic[deck[i]] += 1
            else:
                dic[deck[i]] = 1

        min_cnt = 10000
        for key,cnt in dic.items():
            min_cnt = min(min_cnt, cnt)

        if min_cnt < 2: return  False

        for j in range(2,min_cnt+1):
            flag = 1
            for key,cnt in dic.items():
                if cnt%j != 0: 
                    flag = 0
                    break
            if flag == 1: return True
        return False
```


