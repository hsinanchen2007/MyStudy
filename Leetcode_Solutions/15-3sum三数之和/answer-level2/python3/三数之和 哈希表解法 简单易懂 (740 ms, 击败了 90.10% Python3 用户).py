
![Screen Shot 2020-01-27 at 11.53.30 AM.png](https://pic.leetcode-cn.com/6531f951dbfbef8f59eabc7852020a2b045dd7e228ddebb8061ee469dde5eaf7-Screen%20Shot%202020-01-27%20at%2011.53.30%20AM.png)



# 解题思路

由
a + b + c = 0 
等价于
a + b = -c 

可参考 [两数之和](https://leetcode-cn.com/problems/two-sum/) 问题的哈希表解题方法:

先对数组进行排序(理由稍后解释), 再对排序后的数组进行遍历, 将每个元素的相反数作为key, 元素所在的位置作为value存入哈希表中, 两次遍历数组不断检查 a + b 之和是否存在于哈希表中.

**有以下几个需要注意的点** 

1. 找到满足条件的结果后, 需要将结果数组序列化并存入令一个哈希表中, 以便对结果去重
2. 首先在对 a,b 进行遍历时, 如果当前元素与前一个元素相同可直接跳过以优化性能 (思考: 后一个元素能发现的结果一定会包含在前一个元素的结果中). 另外, 仅在一层循环中加入此逻辑性能最佳. 该逻辑有效的前提是相同的元素需要连在一起, 所以需先对数组进行排序

# 复杂度评估

* 时间复杂度 O(n ^ 2)
* 空间复杂度 O(n)


# 代码

```
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []
        '''先对数组排序, 遍历数组遇到与前一个元素相同的情况可直接跳过'''
        nums.sort()
        target_hash = {-x: i for i, x in enumerate(nums)}
        res = []
        res_hash = {}
        for i, first in enumerate(nums):
            '''当前元素与前一个元素相同时, 可直接跳过以优化性能'''
            if i > 0 and first == nums[i - 1]:
                continue
            for j, second in enumerate(nums[i + 1:]):
                '''检查两数之和是否存在于哈希表中'''
                if first + second in target_hash:
                    target_index = target_hash[first + second]
                    if target_index == i or target_index == i + j + 1:
                        continue
                    '''将找到的结果存入另一个哈希表中, 避免包含重复结果'''
                    row = sorted([first, second, nums[target_index]])
                    key = ",".join([str(x) for x in row])
                    if key not in res_hash:
                        res.append(row)
                        res_hash[key] = True
        return res
```
