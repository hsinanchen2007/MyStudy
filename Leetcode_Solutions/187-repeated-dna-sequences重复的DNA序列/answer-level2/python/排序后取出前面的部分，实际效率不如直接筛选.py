### 解题思路
建立统计信息后，可以采取两种做法：
1. 直接遍历map，取出次数 > 1 的键值
2. 排序map的items，然后取出次数 > 1 的键值，> 1 不成立时，可以停止；

实际做法`2`的效率并不如`1`好。

### 代码

```python
class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        很直观的hash解法，先统计后筛选
        直接使用pythonic的写法，实际更加省内存和time-efficiency
        """
        if len(s) < 10:
            return []
        m = {}
        for i in xrange(0, len(s) - 9, 1):
            if s[i:(i+10)] not in m:
                m[s[i:(i+10)]] = 0
            m[s[i:(i+10)]] += 1
        return [_ for _ in m.keys() if m[_] > 1]
        # 排序的效率是nlogn，然后取到 次数 > 1，就停止的算法，虽然很理想，
        # 但实际并不优越
        # s = sorted(m.items(), key=lambda x: x[1], reverse=True)
        # ret = []
        # for item in s:
        #     if item[1] > 1:
        #         ret.append(item[0])
        #     else:
        #         break
        # return ret

```