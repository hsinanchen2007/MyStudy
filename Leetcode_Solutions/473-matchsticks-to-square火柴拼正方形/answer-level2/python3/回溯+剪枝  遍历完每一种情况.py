
首先定义一个vis数组来记录访问情况，pan函数是判断是否数组每一个元素都用到了，core函数则是用来递归。在每访问一个数组元素i时，则vis[i]=1，再次调用core函数实现深度优先搜索，调用完毕后，vis[i]置0。如果现在的和等于边长，则把现在的和now置零，让函数继续搜索。
```python []
class Solution:
    def makesquare(self, nums: List[int]) -> bool:
        s=0
        for x in nums:
            s+=x
        if s==0:
            return False
        if s%4!=0:
            return False
        q=s/4
        self.p=0
        vis=[0]*len(nums)
        def pan(a):
            s=0
            for i in range(len(a)):
                if a[i]==0:
                    s=1
                    break
            if s==0:
                return True
            return False
        self.temp={}
        def core(now):
            pp=str(vis)             #剪枝
            if pp in self.temp:     #剪枝
                return              #剪枝
            self.temp[pp]=1         
            if self.p==1:
                return
            if now>q:
                return
            if now==q:
                if pan(vis):
                    self.p=1
                    return
                now=0
            for i in range(len(nums)):
                if vis[i]==0:
                    vis[i]=1
                    core(now+nums[i])
                    vis[i]=0
        core(0)
        if self.p==1:
            return True
        return False
```

