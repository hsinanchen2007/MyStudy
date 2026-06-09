### 解题思路
    遍历每个元素, 得到每个元素所需的diff, 看这个diff是否存在于这个nums列表中(除自身外)
    下面用三种方法，一层层优化这题的解法。。。

### 代码


# 方法一: 暴力遍历
# 复杂度: O(n^2)
```python3
def twoSum(nums, target):
    length = len(nums)
    # i/j 都是位置索引
    for i, value in enumerate(nums):
        diff = target - value  # 得到差值(即:在余下的元素中找到该diff值即可)
        j = i + 1 # 因为不能重复利用同个元素, 所以把'位置索引j'加上1
        while j < length: # +-1问题: 不能取到length
            if nums[j] == diff:
                return [i, j]
            j += 1
```
# 执行用时 :6548 ms, 在所有 Python3 提交中击败了5.01%的用户
# 内存消耗 :14.1 MB, 在所有 Python3 提交中击败了78.11%的用户

# 方法二: 先排序 + 首尾递进查找
# 复杂度: O(n*logn+n)
```python3
def twoSum(nums, target):
    sorted_id_lst = sorted(range(len(nums)), key=lambda x: nums[x]) # 记录排序后的位置索引(不会真的对原nums排序)
    left_point = 0 # 记录左边的索引位置
    right_point = len(nums) - 1 # 记录右边的索引位置
    while left_point < right_point:  # 当左边索引位==右边索引位时,退出循环(没有找到target)
        sum = nums[sorted_id_lst[left_point]] + nums[sorted_id_lst[right_point]] # sorted_id_lst是索引位的列表, 取值方法略繁琐
        if sum == target:
            return [sorted_id_lst[left_point], sorted_id_lst[right_point]]
        elif sum < target:
            left_point += 1
        elif sum > target:
            right_point -= 1
```
# 执行用时 :88 ms, 在所有 Python3 提交中击败了49.90%的用户
# 内存消耗 :14.1 MB, 在所有 Python3 提交中击败了79.03%的用户


# 方法三: 哈希表
# 复杂度: O(n)
```python3
def twoSum(nums, target):
    hashmap = {}
    for i, value in enumerate(nums):
        diff = target - value
        if diff in hashmap:
            return [hashmap.get(diff), i] # i应该放在后面的位置
        hashmap[value] = i # 如果hashmap中没有diff值, 则把value作为键/位置索引作为值赋给hashmap(注意位置别颠倒)
```
# 执行用时 :48 ms, 在所有 Python3 提交中击败了95.98%的用户
# 内存消耗 :14.1 MB, 在所有 Python3 提交中击败了78.64%的用户
