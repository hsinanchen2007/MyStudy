```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp=[0]*len(nums)
        if not nums:
            return 0
        for i in range(len(nums)):
            if i==0:
                dp[i]=1
            else:
                try:
                    dp[i]=max([dp[j]+1 for j in range(i) if nums[i]>nums[j]])
                except ValueError:
                    dp[i]=1
        return max(dp)
```
```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        '''当看到题目的要求，我的第一反应也是二分法，关键二分法只是对于排序是nlogn，对于查找是logn
        到底怎么用呢
        这个方法稍微特殊一点，
        创建一个列表，然后列表中如果列表尾部值小于当前数值，直接放入尾部。
        如果列表数值大于尾部，那么需要放到合理的位置，并且替换掉比他大的第一个数。

        '''
        if not nums:
            return 0
        tail=[]
        def search(index1,index2,val,lst):
            if index1==index2:
                return index1
            mid=int((index1+index2)/2)
            if lst[mid]<val<=lst[mid+1]:
                return mid+1
            elif val<=lst[mid]:
                return search(index1,mid,val,lst)
            else :
                return search(mid, index2, val, lst)



        for i in nums:
            #print(tail)
            if not tail:
                tail.append(i)
                continue
            if i >tail[-1]:
                tail.append(i)
            else:
                tail[search(0,len(tail)-1,i,tail)]=i

        #print(tail)
        return len(tail)
```
