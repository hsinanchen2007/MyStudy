根据题意，有且仅有一个环，而且只要返回环在列表中的最后一个节点就可以了。
所以我的想法就是通过删掉没有环的节点，找到环。
只要不断迭代，删除只有一条边相连的节点，删到不能删了，剩下的就是环了。

```
class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        ee=[]
        for i in edges:
            ee.extend(i)          #为了方便写代码把所有节点加到一个列表
        while 1:   
            a=[]  
            for i in range(0,len(ee)-1,2):         #  ee[i]和ee[i+1] 就是每条边的两个节点 
                if ee.count(ee[i])!=1 and ee.count(ee[i+1])!=1 :    #如果 一条边 的两个节点都和其他节点相连（即节点的编号在数组中至少出现两次）
                    a.extend([ee[i],ee[i+1]])                       # 将这条边加入数组a
            if a==ee:                                               
                return [ee[-2],ee[-1]]       # a==ee ，说明已经删到不能再删了，剩下的就是环，返回最后一条边即可
            else:
                ee=a            # 用数组更新ee，更新的ee就是删除一轮后的结果，再继续迭代
```

思路简单清晰，代码简单，新手友好，只不过效率很低，只战胜5%。


