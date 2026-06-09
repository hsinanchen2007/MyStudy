```python
class Solution(object):
    def commonChars(self, A):
        """
        :type A: List[str]
        :rtype: List[str]
        """
        # tmp: A中所有字符串的交集
        tmp = set(A[0])
        for x in A[1:]:
            tmp = tmp & set(x)
        tmp = list(tmp)
        # tmp_cnt: 记录每个交集字符在每个字符串中出现的次数
        tmp_cnt = []
        for x in tmp:
            cnt = A[0].count(x)
            if cnt == 1: # 如果只有1次的话，可以结束循环，减少运算量
                tmp_cnt.append(cnt)
                continue
            for y in A[1:]:
                if cnt > y.count(x):
                    cnt = y.count(x)
                    if cnt == 1:
                        break
            tmp_cnt.append(cnt)
        #构造正确答案
        res = []
        for x in range(len(tmp)):
            for y in range(tmp_cnt[x]):
                res.append(tmp[x])
        return res
```