### 解题思路
用前缀和也超时了，还做了优化，差点超时

### 代码

```python3
class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        #思路：看见这玩意立刻想到前缀和
        m = len(matrix) #行数
        n = len(matrix[0]) #列数
        #对每一个点，统计以它为右下角端点的子矩阵的和满足target的数量
        #建立前缀和数组
        q_table = [[0] * (n+1) for _ in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                q_table[i][j] = matrix[i-1][j-1] + q_table[i][j-1] + q_table[i-1][j] - q_table[i-1][j-1]
        #完成前缀和数组后，进行遍历
        #写一个计算元素和的函数
        def caculate(x1,y1,x2,y2):
            #x1,y1是右下角点，x2,y2是左上角点
            return q_table[x1][y1] - q_table[x2-1][y1] - q_table[x1][y2-1] + q_table[x2-1][y2-1]
        res = 0
        #这里对查找做一个优化，在某两列间进行搜索时，存储行不同时的值
        for y1 in range(1,n+1):
            for y2 in range(1,y1+1):
                pre = collections.defaultdict(int)
                pre[0] = 1
                for x1 in range(1,m+1):
                    cal = caculate(x1,y1,1,y2)
                    if cal - target in pre:
                        res += pre[cal-target]
                    pre[cal] += 1
        return res

```