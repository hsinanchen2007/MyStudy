### 解题思路
此处撰写解题思路
本来没看标签之前想到的是hash的方法，就是看某个元素的个数，让他减到1即可，如何减到1，
标准在于这个数一直增加到当前数不再整个字典里面即可。然后还优化了一下，结果当数组很长的时候还是没有通过。

看了标签发现纯粹是一个数组问题，没有其他多余的标签，于是想着先排序，然后递增，这样时间复杂度最多是O(nlogn),应该是没问题的
然后代码走一遍，排序过后，发现如何让每个数字不重复，就是看当前的数字至少比前面的要大1才可以，不然就加到大1即可。跑完发现时间过了。

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        # dic = collections.Counter(A)
        # dd = copy.deepcopy(dic)
        # ans = 0
        # for k,v in dic.items():
        #     while v>=2:
        #         t = k
        #         while t in dd:
        #             t+=1
        #         ans += t-k
        #         dd[t]=1
        #         # dd[k]-=1
        #         v-=1
        # # print(dd)
        # return ans
        A.sort()
        ans = 0 
        for i in range(1,len(A)):
            if A[i]<=A[i-1]:
                ans+=1+A[i-1]-A[i]
                A[i]=A[i-1]+1
        return ans
            






```