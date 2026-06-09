### 思路
本题的思路在于当前层的最优解是需要经过与上一层的所有最优解进行组合得到的，也就是说，不能直接将上一层最小的数与当前层的每个节点进行比较，这样显然是没有意义的。
组合的思路就在于for的子循环中的三个判断。
### 拓展思考
值得思考的一个问题是：当前层的最小路径是根据上一层和当前层进行组合从而确定的，所以我们如果想获得最短路径的话，怎么办？
其实很简单，仔细思考就知道：在最后的RSC里面已经存储着每行的所有可能的路径值，最后对RSC的每行取最小值的位置就可以得到遍历的位置了，如果每行的结果有相同的，那么没关系，比如这题的表示例子的结果：[[0],[0],[1],[1]] 代表着RSC中每行最小值的位置，挨个的打印就可以了，如果其中有一行存在相同的，比如第二行的[3,4]是[3,3],那么路径就是：[[0],[0,1],[1],[1]] ，我们可以挨个的for一遍。

### 本题的代码
```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        ks = triangle; RSC=[ks[0]]
        for level in range(1,len(ks)):
            ls =ks[level];ls1=RSC[level-1];RS=[]
            for i in range(len(ls)):
                if i==0:
                    RS.append(ls[i]+ls1[i])
                elif i==len(ls)-1:
                    RS.append(ls[i]+ls1[i-1])
                else:

                    RS.append(min(ls[i]+ls1[i-1],ls[i]+ls1[i]))
            RSC.append(RS)
        # print(RSC)
        return min(RSC[-1])
```