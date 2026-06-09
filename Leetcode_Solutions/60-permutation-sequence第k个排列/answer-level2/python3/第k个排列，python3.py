方法一：回溯（超时）
```
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        res=0
        self.result=""

        def backtrack(s,nums):
            nonlocal res
            if len(s)==n:
                res+=1
                if res==k:
                    self.result=s
                return 
            for i in range(len(nums)):
                num=nums[i]
                del nums[i]
                backtrack(s+str(num),nums)
                nums.insert(i,num)

        nums=[i for i in range(1,n+1)]
        backtrack("",nums)
        return self.result
```
方法二：数学
```
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        res=""
        nums=[str(i) for i in range(1,n+1)]
        div=1
        k-=1
        for i in range(1,n):
            div*=i
        for i in range(n-1,0,-1):
            res+=nums[k//div]   #找分组
            del nums[k//div]
            k%=div
            div//=i
        res+=nums[0]
        return res

```


