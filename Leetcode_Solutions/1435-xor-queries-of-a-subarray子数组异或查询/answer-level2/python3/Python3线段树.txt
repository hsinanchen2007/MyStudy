不了解异或公式，用了个笨办法，时间复杂度O(m + nlog(n)),m为建树时间，n为查询次数
```
class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        class Tree(object):
            def __init__(self,l,r):
                self.l=l
                self.r=r
                self.value=0
                mid=(l+r)//2
                if l < r:
                    self.left=Tree(l,mid);
                    self.right=Tree(mid+1,r);
            def setvalue(self,x,val):
                if(self.l==self.r):
                    self.value=val
                    return;
                mid=(self.l+self.r)//2;
                if(x<=mid):
                    self.left.setvalue(x,val)
                else:
                    self.right.setvalue(x,val)
                self.value=self.left.value^self.right.value
            def ask(self,l,r):
                if(l<=self.l and r>=self.r):
                    return self.value;
                val=0;
                mid=(self.l+self.r)//2;
                if(l<=mid):
                    val^=self.left.ask(l,r);
                if(r>mid):
                    val^=self.right.ask(l,r);
                return val;

        arrlen = len(arr)
        tree = Tree(1,arrlen)
        for i,a in enumerate(arr):
            tree.setvalue(i+1, a)
        
        ans = []
        for query in queries:
            ans.append(tree.ask(query[0]+1, query[1]+1))
        return ans
```
