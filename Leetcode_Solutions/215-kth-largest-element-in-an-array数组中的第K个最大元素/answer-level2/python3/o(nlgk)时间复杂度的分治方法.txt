1. 当数组长度>2k,从中间切成两部分，分别求最大的k个元素列表，然后两路归并回来。
2. 当数组长度<=2K,用排序求最大的k个元素列表
3. 时间复杂度o(nlgk),当n>>k时比直接排序o(nlgn)好。
```
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def helper(num,k):
            if len(num)<=2*k:
                num = sorted(num,key=lambda x:-x)
                return num[:k]
            else:
                #如果数组长度大于2k，切成两半分别求最大的k个元素
                m = len(num) // 2
                L = helper(num[:m],k)
                R = helper(num[m:],k)
                #两路归并
                ans = []
                l = 0
                r = 0
                while l+r < k:
                    if L[l] > R[r]:
                        ans.append(L[l])
                        l += 1
                    else:
                        ans.append(R[r])
                        r += 1
                return ans
        fk = helper(nums,k)
        return fk[-1]
```
