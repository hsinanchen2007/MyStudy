### 解题思路
1. 先找出所有符合的区间， 这里面有个坑，str.find只是返回第一个位置， 实际上需要用while循环继续向后找。
2. 合并区间
3. 根据合并好的区间插入<b>和</b>。 这里面又有一个坑......先插入前面的，会导致后面的插入出问题，所以要先将最后的区间先逆序。这样先插入后面的部分， 那么不会影响到前面的插入...
4. 感觉这道题可以算中等了！

### 代码

```python3
class Solution:
    def boldWords(self, words: List[str], S: str) -> str:
        stack = []
        idx = []
        S_list = list(S)

        for word in words:
            loc = S.find(word)
            while loc != -1:
                idx.append([loc, loc + len(word)])
                loc = S.find(word, loc + 1)

        idx = sorted(idx)

        for i in idx:
            if len(stack) == 0:
                stack.append(i)
            else:
                prev = stack[-1]
                if prev[1] >= i[0]:
                    stack[-1] = [prev[0], max(prev[1], i[1])]
                else:
                    stack.append(i)
        

        for mark in stack[::-1]:
            S_list.insert(mark[1], '</b>')
            S_list.insert(mark[0], '<b>')
        S = ''.join(S_list)
        return S
        

```