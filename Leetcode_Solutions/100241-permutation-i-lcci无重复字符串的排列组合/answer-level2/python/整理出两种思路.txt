### 解题思路
方法一：用队列一步步更新字符组合列表
方法二：用递归遍历并记录字符路径

### 代码

```python
class Solution(object):
    def permutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        # 方法一  利用队列
        '''
        if S == '':
            return []
        ans = [S[0]]
        n = len(S)
        for i in range(1, n):
            add = S[i]
            while len(ans[0]) == i:
                a = ans.pop(0)
                for k in range(i+1):
                    ans.append(a[:k]+add+a[k:])
        return ans
        '''
    # 方法二  利用递归
    def permutation(self, S):
        def backtrap(S, path, res):
            if len(S) == 0:
                res.append(path)
                return
            for i in range(len(S)):
                a = S[i]
                backtrap(S[:i]+S[i+1:], path+a, res)
            return res
        path = ''
        res = []
        return backtrap(S, path, res)



                    



```