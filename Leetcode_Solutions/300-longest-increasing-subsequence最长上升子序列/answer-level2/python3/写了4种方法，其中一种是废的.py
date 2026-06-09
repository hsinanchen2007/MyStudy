### 解题思路
懒得写文字了，先凑合着看吧

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # way1: 动态规划，dp表示以xx为结尾的最长子序列
#         if len(nums)== 0:
#             return 0
#         dp = [1 for i in range(len(nums))]
        
#         for i in range(len(nums)):
#             for j in range(i):
#                 if(nums[i] > nums[j]):
#                     dp[i] = max(dp[i],dp[j]+1)
                
#         return max(dp)
    
        # 贪心，二分查找
        # 使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，因此我们希望每次在上升子序列最后加上的那个数尽可能的小
#         d = []
#         for n in nums:
#             if not d or n>d[-1]:
#                 d.append(n)
            
#             else:
#                 l,r = 0, len(d)-1 
#                 while(l<=r):
#                     mid = l + (r-l)//2
#                     # 等于的时候也尽量往左走
#                     if d[mid] >=  n:
#                         r = mid - 1
#                     else:
#                         l = mid + 1
                
#                 d[l] = n
            
#         return len(d)
        
        # 牌接龙法
        paidui = []
        piles = 0
        for i in range(len(nums)):
            cur_poker = nums[i]
            left = 0
            right = len(paidui)
            
            # 找左边界
            while(left < right):
                mid = left + (right - left)//2
                if(paidui[mid] > cur_poker):
                    right = mid
                elif(paidui[mid] < cur_poker):
                    left = mid + 1
                elif(paidui[mid] == cur_poker):
                    right = mid
            # 这里有一点绕，这里要实现的功能不是精确查找，而是只要最后搜索落在的地方不是牌堆之外就能被放上
            # 因为接龙的规则是只要小于牌堆顶就行，搜索的左边界保证每次都是把牌放在能放的最左边
            if(left < len(paidui)):
                paidui[left] = cur_poker
            else: 
                piles += 1
                paidui.append(cur_poker)
            
        return piles
          
    # 我吐血，我写了一个最长连续子序列的二分算法，他吗的这个题目不要求连续的，我一口老血
    # 我debug了很久，后来发现和我想的答案都不一样，醉了
#         def solver(left,right):
#             if left == right:
#                 return 1
            
#             mid = left + (right-left)//2
            
#             left_num = solver(left,mid)
#             right_num = solver(mid+1,right)
            
#             if 
            
#             for i in range(left,mid+1):
#                 if i == left:
#                     ans_l = 1
#                     continue
#                 if(nums[i] > nums[i-1] ):
#                     ans_l += 1
#                 else:
#                     ans_l = 1
            
#             for j in range(mid,right+1):
#                 if j == mid:
#                     ans_r = 1
#                     continue
#                 if(nums[j] > nums[j-1]):
#                     ans_r += 1
#                 else: 
#                     ans_r = 1
            
#             for i in range(mid,left-1,-1):
#                 if i == mid:
#                     ans_ml = 1
#                     continue
#                 if nums[i] < nums[i+1]:
#                     ans_ml += 1
#                 else:
#                     break
                    
#             for i in range(mid,right):
#                 if i == mid:
#                     ans_rl = 1
#                     continue
#                 if nums[i] > nums[i-1]:
#                     ans_rl += 1
#                 else:
#                     break   
            
#             return 
        
#         return solver(0,len(nums)-1)
```