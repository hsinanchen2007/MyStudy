```
class Solution:
    def numberOfPatterns(self, m: int, n: int) -> int:
        viewed=[]
        self.res=0
        graph = {
            1: {3: 2, 7: 4, 9: 5},
            2: {8: 5},
            3: {1: 2, 7: 5, 9: 6},
            4: {6: 5},
            5: {},
            6: {4: 5},
            7: {1: 4, 3: 5, 9: 8},
            8: {2: 5},
            9: {1: 5, 3: 6, 7: 8},
        }
        ret=0
        dfs(1,[1])
        ret=4*self.res
        self.res=0
        dfs(2,[2])
        ret+=4*self.res
        self.res=0
        dfs(5,[5])
        ret+=self.res
        
        return ret
```
1.字典key-value中value可以还是一个字典
2.剪枝不一定是逻辑剪枝，125和剩下的重复计算，一开始就可以只算这三种情况，不能一开始就陷入问题细节，要从宏观想一想有时会节省很多时间。