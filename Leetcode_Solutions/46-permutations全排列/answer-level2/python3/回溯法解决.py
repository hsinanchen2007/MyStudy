### 解题思路
需要注意一点的地方是Python 赋值过程中不明确区分拷贝和引用，一般对静态变量的传递为拷贝，对动态变量的传递为引用,回溯法中变量一直在变化,所以赋值的时候要进行拷贝而不是引用

### 代码

```python3
class Solution:
    def permute(self, nums: [int]) -> [[int]]:#nums=[1,2,3]
        res=[]
        if len(nums)==0:
            return res
        ll=[]
        in_or_not=[False]*len(nums)#判断这个元素是否已经遍历过
        def dfs(ll:list,index):
            if index == (len(nums)):
# Python 赋值过程中不明确区分拷贝和引用，一般对静态变量的传递为拷贝，对动态变量的传递为引用,所以这个地方如果只是res.append(ll)的话,由于ll是动态变量,所以res的值会发生变化
                res.append(ll.copy())
                return
            for j in range(len(nums)):
                if not in_or_not[j]:
                    in_or_not[j]=True
                    ll.append(nums[j])
                    dfs(ll,index+1)
                    #接下来回溯
                    ll.pop(-1)#在递归回退的时候要将添加到其中的元素推出
                    in_or_not[j]=False

        dfs(ll,0)
        return res
```