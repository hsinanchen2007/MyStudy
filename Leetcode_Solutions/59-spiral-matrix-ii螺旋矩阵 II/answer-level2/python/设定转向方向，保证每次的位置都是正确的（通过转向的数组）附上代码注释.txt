```
class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        # 预先生成一个1到n2的数组
        m=[i for i in range(1,n**2+1)]
        # 生成一个记录某单元是否已经访问的标记
        flags=[[False]*n for i in range(n)]
        res=[['a']*n for i in range(n)]
        
        # 初始化
        r,c,di=0,0,0
        # 顺时针的转向
        dr,dc=[0,1,0,-1],[1,0,-1,0]
        while m:
            # 当m还没有清空
            # 每次加入完后 m数组将第一个元素弹出 因此每次都是m[0]
            # print(r,c)
            res[r][c]=m[0]
            # 标识访问
            flags[r][c]=True
            # m将第一个元素弹出
            m.pop(0)
            # 计算下一次的位置
            rr,cc=r+dr[di],c+dc[di]
            # 还没到边界 且下一个方向没有被访问过
            if 0<=rr<n and 0<=cc<n and not flags[rr][cc]:
                r,c=rr,cc
            # 需要拐弯或者下一个单元已经被访问需要换方向
            else:
                di=(di+1)%4
                r,c=r+dr[di],c+dc[di]
        return res
            
            
            
        
```
