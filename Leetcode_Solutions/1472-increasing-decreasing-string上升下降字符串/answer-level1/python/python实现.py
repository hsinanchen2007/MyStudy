### 解题思路
每次对当前序列取非重复值排序，分别在奇偶数循环里面对排序结果取正反序添加到结果末尾

### 代码

```python3
class Solution:
    def sortString(self, s: str) -> str:
        n = len(s)
        s = list(s)
        res = ''
        rev_flag = 0
        while len(res) < n:
            temp = sorted(set(s))[::(-1)**rev_flag]
            res += ''.join(temp)
            for i in temp:
                s.remove(i)
            rev_flag += 1
        return res
                

            



        

```