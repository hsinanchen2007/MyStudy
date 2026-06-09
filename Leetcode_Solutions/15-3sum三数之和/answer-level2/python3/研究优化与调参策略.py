### 解题思路
采用3层for循环来求解此问题时，在数据量稍大且数据分布均匀的情况下（数据规模大于2999），会导致程序运算超时；
前期基于3层for循环优化程序，采用数据去重（多于双副本）、hash set查找以及剪枝优化等策略，仍未使程序性能有大幅度提升；
程序耗时处在于无论采用多少种优化策略，嵌套循环仍做大量无用遍历。故摒弃之，取双指针而代之；
引用一层for遍历，此遍历提供第一个数字。第2、3个数字分别从头部和尾部进行遍历，过程神似快排中的一次遍历；
在遍历过程中，以剪枝优化辅助之，并以while实现数据去重；
最终可求解。
### 此思路与传统嵌套循环的区别：
通过哨兵模式节省了大量无用的遍历与比较运算的时间，运用此算法的前提是需要对三数之和的性质（特征）有一定理解。
### 代码

```python3

class Solution:
    def threeSum(self, nums):
        result = []
        # 排序
        nums.sort()
        length = len(nums)

        for k in range(length-2):
            if nums[k] > 0:
                return result
            if k > 0 and nums[k] == nums[k - 1]:
                continue
            # 初始化哨兵i j的索引
            i , j = k+1, length-1
            while i < j:
                sum_num = nums[i] + nums[j] + nums[k]
                if sum_num < 0 :    
                    i += 1
                    # 去重
                    while i < j and nums[i] == nums[i-1]:
                        i += 1
                elif sum_num > 0:
                    j -= 1
                    # 去重
                    while i < j and nums[j] == nums[j+1]:
                        j -= 1
                else:
                    result.append([nums[i], nums[j], nums[k]])
                    i += 1
                    j -= 1
                    # 去重
                    while i < j and nums[i] == nums[i-1]:
                        i += 1
                    while i < j and nums[j] == nums[j+1]:
                        j -= 1
        return result



```