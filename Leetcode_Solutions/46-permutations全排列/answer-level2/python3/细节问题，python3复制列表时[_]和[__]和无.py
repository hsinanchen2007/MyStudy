主要讲第8行，一个新手问题。（代码copy的）
为什么用tem[:]

1.对于第8行改为res.append(tem)错的原因是因为，引用了tem,id还是相同的
>>> l=[1,2,3]
>>> a=[]
>>> id(l)
1545335271176
>>> a.append(l)
>>> id(a[0])
1545335271176

2.然后Python 3中[:]和[::]完全相等：浅拷贝完全相等
>>> z1=l[:]
>>> z2=[::]
>>> z2=l[::]
>>> id(z1)==id(z2) and id(z1)!=id(l)
>>> True
```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def backtrack(nums,tem):
            #找结束条件
            if nums==[]:
                if tem not in res:
                    #print("intput：",tem)
                    res.append(tem[:])###主要讲这 8行
                    #print(res)
            else:
                for i in range(len(nums)):
                    tem.append(nums[i])
                    backtrack(nums[0:i]+nums[i+1:],tem)
            #边界情况
            if tem == []:
                return
            tem.pop()

        res = []
        tem = []
        backtrack(nums,tem)
        return res
作者：chun-meng-da-xiao-yang
链接：https://leetcode-cn.com/problems/permutations/solution/chao-qiang-gifzhu-ni-li-jie-shi-yong-4chong-fang-f/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```
