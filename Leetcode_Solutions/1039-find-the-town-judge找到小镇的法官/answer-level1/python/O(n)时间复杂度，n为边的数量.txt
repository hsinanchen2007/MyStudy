**解题思路：**记录每个结点的入度和出度，按照题目要求，出度为0，入度为N-1的结点值就是法官

## 示例代码
![截图1569149091.png](https://pic.leetcode-cn.com/7ef4f6cecb29f2b90a20389db99bf3a7fd4f60df0d37cbc2e718b374a595d74b-%E6%88%AA%E5%9B%BE1569149091.png)
    
    def findJudge(self, N, trust):
        """
        :type N: int
        :type trust: List[List[int]]
        :rtype: int
        """
        if N == 1:
            return 1
        #定义入度和出度
        in_d = [0 for i in range(N)]
        out_d = [0 for i in range(N)]
        for a,b in trust:
            in_d[a-1] += 1
            out_d[b-1] += 1
        for i in range(N):
            if in_d[i] == 0 and out_d[i] == N-1:
                return i+1
        return -1