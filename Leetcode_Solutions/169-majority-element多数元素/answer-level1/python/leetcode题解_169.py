### 解题思路
1.hashmap法
2.排序法
3.随机化
4.分治
5.投票法
参考：官方题解

### 代码

```python3
class Solution:
    def majorityElement_1(self, nums: List[int]) -> int:
        # 1.hashmap方法
        # 使用哈希映射存储每个元素和对应出现的次数
        # 时空复杂度均为O(n)
        counts = collections.Counter(nums)
        return max(counts.keys(), key=counts.get)
    
    def majorityElement_2(self, nums: List[int]) -> int:
        # 2.排序法
        # 如果将所有元素按照单调递增或递减的顺序排列，中间的数(下标n/2的地板)一定是众数（即多数元素）
        # 时间复杂度O(nlogn),空间复杂度O(logn)
        nums.sort()
        return nums[len(nums)//2]
    
    def majorityElement_3(self, nums: List[int]) -> int:
        # 3.随机化
        # 根据题意，因为众数占的超过半数，我们随机挑选一个数，然后检查其是不是众数，直到找到为止
        # 时间复杂度为O(n)，空间复杂度为O(1)
        majority_count = len(nums)//2
        while True:
            candidate = random.choice(nums)
            if sum(1 for elem in nums if elem == candidate) > majority_count:
                return candidate
    
    def majorityElement_4(self, nums: List[int]) -> int:
        # 4.分治法
        # 将数组半分，众数一定出现在其中一部分，所以定义子问题为分别求出两部分的众数，再从中找出真正的众数
        # 时间复杂度为O(nlogn),空间复杂度为O(logn)
        def majority_element_rec(low, high):
            # 求子问题
            # base case:当数组分到长度为1时，一定包含众数
            if low == high:
                return nums[low]
            # 二分数组
            mid = (high-low)//2 + low
            left = majority_element_rec(low, mid)
            right = majority_element_rec(mid+1, high)
            # 如果两数组求出的众数一样
            if left == right:
                return left
            # 统计两边众数出现的次数，选出获胜的作为结果
            left_count = sum(1 for i in range(low,high+1) if nums[i]==left)
            right_count = sum(1 for i in range(low,high+1) if nums[i]==right)
            return left if left_count > right_count else right
        return majority_element_rec(0, len(nums)-1)
    
    def majorityElement_5(self, nums: List[int]) -> int:
        # 5.Boyer-Moore投票法
        # 将众数记为1，其余数记为-1，和一定大于0
        # 初始化的时候默认第一个是众数，过程中更新了真正的众数
        # 时间复杂度为O(n),空间复杂度为O(1)
        count = 0
        candidate = None
        
        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)
        return candidate
        
    def majorityElement(self, nums: List[int]) -> int:
        return self.majorityElement_4(nums)
```