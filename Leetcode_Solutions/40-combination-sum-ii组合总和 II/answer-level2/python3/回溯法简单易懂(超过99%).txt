![image.png](https://pic.leetcode-cn.com/f00cfe6ff7f5db9b43730dc1cac2cb7350f89dfdad9507f84dded0184b697514-image.png)

我觉得用时还不错,就贴上来我的方法和大家分享
- 此题与39题类似,但是此题不允许重复使用candidates中的元素,那么说明我们回溯时,应该从candidates[i+1:]开始,这样可以避免我们使用已使用过的元素,具体的代码如下:
`backtrace(candidates[i+1:],temp[:],target,res)`
- 我们还需要注意回溯时,应该去重剪枝,在对candidates进行遍历时,我们下一个元素不应该与我们上一个元素相同,具体代码如下:
`if i==0 or candidates[i]!=candidates[i-1]:`;
```py
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def backtrace(candidates,temp,target,res):
            for i in range(len(candidates)): #对candidates中的每个元素进行遍历
                if i==0 or candidates[i]!=candidates[i-1]: #剪枝,比如candidates为[1,1,2,6,7,10]我们使用过1元素了,那么我们不能再次使用1元素,注意这两个元素不是同一个元素,而是指值相同
                    temp.append(candidates[i])
                    if sum(temp)==target: #找到了,加入res
                        res.append(temp)
                        return #那么后面的值也不需要遍历了,因为一定比当前值大
                    elif sum(temp)>target:
                        return #比target还大,那么后面的值也不需要遍历了,因为一定比当前值大
                    backtrace(candidates[i+1:],temp[:],target,res) #递归
                    temp.pop() #回溯
        temp=[]
        res=[]
        candidates.sort() #需要先排序,这样后面的剪枝才有意义
        backtrace(candidates,temp,target,res)
        return res

```

