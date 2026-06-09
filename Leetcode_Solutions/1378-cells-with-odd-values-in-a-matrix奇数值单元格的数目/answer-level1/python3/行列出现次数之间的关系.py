![屏幕快照 2019-11-27 下午10.02.36.png](https://pic.leetcode-cn.com/caa78a74eb8003e6810707d302ce01c567e0c24c21b9e566547dac9d93255b54-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-11-27%20%E4%B8%8B%E5%8D%8810.02.36.png)

class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        row1 = [i[0] for i in indices]  #获取操作行
        col1 = [i[1] for i in indices]  #获取操作列
        row2 = set(row1) #行去重
        col2 = set(col1) #同上
        row = [r for r in row2 if row1.count(r)%2!=0] #如果行出现的次数是奇数次，加入结果队列
        col = [c for c in col2 if col1.count(c)%2!=0] #同上
        return len(row)*m+len(col)*n-len(row)*len(col)*2 #奇数行x总列数+奇数列x总行数-重叠元素个数(奇数行x奇数列x2)

