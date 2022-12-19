```
from collections import defaultdict
        # 统计字母的词频
        dic = defaultdict(int)
        for i in s:
            dic[i] += 1
        # count计数，分别对应0-9的数量
        count = [0 for i in range(10)]
        count[2],count[4],count[6],count[8],count[0] = dic['w'],dic['u'],dic['x'],dic['g'],dic['z']
        count[7],count[5],count[3] = dic['s'] - count[6],dic['f']-count[4],dic['h']-count[8]
        count[9] = dic['i'] - count[5]-count[8]-count[6]
        count[1] = dic['o'] -count[2]-count[4]-count[0]
        letter = [str(i) for i in range(10)]
        res = ''
        for i in range(10):
            res += letter[i]*count[i]
        return res
```
