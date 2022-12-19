### 解题思路
简单易懂，代码精简
![image.png](https://pic.leetcode-cn.com/3e6b58e48bf20719ee2e3f8dd83c1490509eab5a5f65fc24417cd1eabf12ef1a-image.png)

### 代码

```python
class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.n=len(nums)
        self.tree=[0]*self.n+nums
        for i in range(self.n-1,0,-1):
            self.tree[i]=self.tree[i<<1]+self.tree[i<<1|1]  #父节点等于子节点之和，|1 作用是加一

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: None
        """
        n=self.n+i
        self.tree[n]=val
        while n>1:
            self.tree[n>>1]=self.tree[n]+self.tree[n^1]  #让更新节点与更新节点的兄弟节点求和，然后更新父节点的值；然后在指向父节点
            n>>=1

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        res=0
        l,r=self.n+i,self.n+j
        while l<=r:
            if l&1: #如果l为右节点,加上该值，l指向下一节点
                res+=self.tree[l]
                l+=1

            if not r&1: #如果r不为右节点,即为左节点，加上该值，r指向上一节点
                res+=self.tree[r]
                r-=1
            l>>=1
            r>>=1
        return res


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
```