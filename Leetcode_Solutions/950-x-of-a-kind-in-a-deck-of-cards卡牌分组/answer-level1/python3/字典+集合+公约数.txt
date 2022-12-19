### 解题思路
1. 特判：若数组元素小于2，则不可能满足条件，直接返回False；
2. 将数组中各个整数及对应出现的次数存储在字典中，整数为键，次数为值；
3. 由于当多个整数出现次数一样时，只需考虑一次该频次是否满足条件即可，因此对字典的值求集合，得到排序且去重的频次；
4. 判断集合中的频次的公约数是否在[2,最小频次]之间，若是则满足条件。

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        if len(deck) < 2: return False
        # 计算各个整数出现的次数，并保存在字典里
        cnt = dict()
        for i in deck:
            if i not in cnt:
                cnt[i] = 1
            else: cnt[i] += 1
        cnt1 = list(set(cnt.values())) # 去重
        for d in range(2, cnt1[0]+1): # 公约数
            res = True
            for i in cnt1:
                if i % d != 0:
                    res = False
            if res: return res
        return False
```