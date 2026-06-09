执行用时 :
100 ms, 在所有 Python3 提交中击败了96.92%的用户
内存消耗 :
14.1 MB, 在所有 Python3 提交中击败了100.00%的用户
```
class Solution:
    def numSmallerByFrequency(self, q: List[str], w: List[str]) -> List[int]:
        su, dic, lis = len(w), dict(), list()
        for i in range(1, 12):
            dic[i] = 0
        for i in w:
            ch, index = i[0], 0
            for j in i:
                if ord(ch) > ord(j):
                    index = 1
                    ch = j
                elif ch == j:
                    index += 1
            dic[index] += 1
        for i in range(1, 12):
            dic[i] = su - dic[i]
            su  = dic[i]
        for i in q:
            ch, index = i[0], 0
            for j in i:
                if ord(ch) > ord(j):
                    index = 1
                    ch = j
                elif ch == j:
                    index += 1
            lis.append(dic[index])
        return lis
```
