### 解题思路
此处撰写解题思路
对于[num in nums]利用插入搜索法搜索target-num,时间复杂度为O(nlog(logn))~O(n^2)，nums分布越是均匀搜索速度越快。
执行用时 :256 ms, 在所有 Python3 提交中击败了100.00%的用户
内存消耗 :24.6 MB, 在所有 Python3 提交中击败了100.00%的用户
### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 插入搜索num
        def insertfind(num,start,end):
            # 在【start，end】内查找num，若找到则返回[True,index]，否则返回[False,前一个或下一个值得索引]
            min_ = start if start > 0 else 0
            max_ = end if end < len(nums) else len(nums)-1
            mid = 0
            while min_ <= max_:
                # 没找到返回[False,前一个或下一个值得索引]
                if nums[min_] > num:
                    return [False,min_-1 if min_ -1 > 0 else 0]
                if nums[max_] < num:
                    return [False,max_+1 if max_+1 < len(nums) else len(nums)-1]
                # 防止除数为零
                if min_ == min_:
                    mid = max_
                else:
                    mid = min_ + (max_ - min_)*(num - nums[min_])//(nums[max_] - nums[min_])
                
                if nums[mid] == num:
                    return [True,mid]
                elif nums[mid] > num:
                    max_ = mid - 1
                else:
                    min_ = mid + 1

        length = len(nums)
        min_ = 0
        # 排除大于target的部分，减少搜索工作
        max_ = insertfind(target,0,length-1)[1]
        for num in nums[min_:max_]:
            # 此处可根据判断num 与target-num的大小进一步缩小搜索范围
            if insertfind(target-num,min_,max_)[0]:
                # 搜索到了target-num
                return [num,target-num]
        # 没有结果
        return []

            


```