回溯算法，采用递归实现，递归标记当前运行到第i个字符；和当前的满足条件的最长字符tmp；从i到i+1个字符；可以选择：
1. 如果not (set(tmp) & set(arr[i]))；即字符不重复，可以选择添加或者不添加（不添加可能后面有更长的s）
2. 如果字符重复，则只能选择不添加
3. 终止条件，递归到l+1字符
```
class Solution():
    def maxLength(self, arr):

        t = []
        for s in arr:
            if len(set(s)) == len(s):
                t.append(s)
        arr = t[:]

        def dfs(i, tmp):

            if i >= len(arr):
                return len(tmp)
            else:
                if not (set(tmp) & set(arr[i])):
                    return max(dfs(i+1,tmp+arr[i]),dfs(i+1,tmp))
                else:
                    return dfs(i + 1, tmp)

        l=dfs(0,'')
        return l
```
