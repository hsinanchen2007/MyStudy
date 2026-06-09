在所有 Python 提交中击败了88.49%的用户

- string.split('规则')
- '规则'.join(string)
- for i in list[::-1] 从后往前迭代
- list.insert(位置, 值)

```
class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        D = {}
        for i in cpdomains:
            # 次数, 字符串
            count, string = i.split()
            seqL = []
            for j in string.split('.')[::-1]:
                # 在特定的位置上插入数据
                seqL.insert(0, j)
                seqStr = '.'.join(seqL)

                if seqStr in D:
                    D[seqStr] += int(count)
                else:
                    D[seqStr] = int(count)
        L = []
        for key, value in D.items():
            L.append(str(value) + ' ' + key)
        return L
```
