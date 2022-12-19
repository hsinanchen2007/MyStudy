![image.png](https://pic.leetcode-cn.com/2577a44158f8f8b904bed1c1cdb9bac0c3dd6245b62b2cbda8cdbbc477261e4e-image.png)


```
'''
要能够分成三段
1肯定是均分在这段里面的，要不然三段数值不可能相等
所以先统计1个数，不是三的倍数就不用再继续了，假设1总个数是n

然后从前到后把包含n // 3 且头尾都是1的子串的结束位置找到，
首先每个子串的数值肯定必须是相等的，
每个子串前面补0对数值是没有影响的，但是后面补0会让值翻一倍
我们看最后那个子串后面接了多少个0，假设接了m个0，那这m个0
只能接在子串后面，要不然没办法把这m个0消耗掉，所以前面两个子串
的后面接的0的个数必须大于等于m, 否则做不到三个数相等，因为前面
两个子串的尾巴上的0不够补，能满足上面的条件就找到了一组解


'''

from typing import List
class Solution:
    def threeEqualParts(self, A: List[int]) -> List[int]:
        one_pos = [i for i in range(len(A)) if A[i] == 1]
        one_cnt = len(one_pos)

        if one_cnt % 3 != 0:
            return [-1, -1]

        if one_cnt == 0:
            # 全是0， 随便返回一个i, j结果都是对的
            return [0,2]

        # 不是全0情况，答案一定是唯一的, 先保证三个子串数值是一样的
        i, j = 0, one_cnt // 3
        sub = one_pos[i] - one_pos[j]
        while i < one_cnt // 3:
            if one_pos[i] - one_pos[j] != sub:
                return [-1, -1]
            i, j = i+1, j+1

        i, j = one_cnt // 3, one_cnt // 3 * 2
        sub = one_pos[i] - one_pos[j]
        while i < one_cnt // 3 * 2:
            if one_pos[i] - one_pos[j] != sub:
                return [-1, -1]
            i, j = i + 1, j + 1


        # 检查尾巴上的0个数是否符合要求
        tail_zero_cnt = len(A) - 1 - one_pos[-1]
        pos1, pos2 = one_pos[one_cnt//3 - 1], one_pos[one_cnt//3 * 2 - 1]

        if one_pos[one_cnt // 3] - pos1 - 1 >= tail_zero_cnt and one_pos[one_cnt // 3 * 2] - pos2 - 1 >= tail_zero_cnt:
            return [pos1+ tail_zero_cnt, pos2+1+tail_zero_cnt]
        return [-1, -1]
```
