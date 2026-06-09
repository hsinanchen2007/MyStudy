
这道题和 [Leecode 第78题 子集 ](https://leetcode-cn.com/problems/subsets/)  差不多一样，区别是本题出现了重复数字，且结果不允许重复。78题的解题方法包括递归回溯、循环迭代、状态分配（基于字典、矩阵、位运算）三种方法。本题在78题代码的基础上添加某些限制条件即可。  



**方法一、递归回溯**  

相较于**78题**的区别是：  
1、在调用 `backtrack()` 之前先将 `nums` 数组排序  
2、当退出回溯函数 `backtrack` 并撤销选择 `path.pop()` 之后，判断后面是否有相同的数字，如果有，就跳过。  

78题代码  

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def backtrack(first = 0, curr = []):
            if len(curr) == k:  
                output.append(curr[:])
                return
            for i in range(first, n - (k - len(curr)) + 1):
                curr.append(nums[i])
                backtrack(i + 1, curr)
                curr.pop()
        
        output = []
        n = len(nums)
        for k in range(n + 1):
            backtrack()
        return output
```

90题代码

```python
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def backtrack(first = 0, path = [], last=[]):
            path_len = len(path)
            if path_len == k:
                output.append(path[:])
                return
            i = first
            while i < n - (k - path_len) + 1:  # 改成while循环
                path.append(nums[i])  # 选择
                backtrack(i + 1, path, last)  # 回溯
                path.pop()  # 退出回溯 撤销选择
                while i + 1 < len(nums) and nums[i] == nums[i+1]:  # 添加的部分限制条件，如果当前位置后面有相同数字，就跳过。
                    i += 1
                i += 1

        nums.sort()  # 在调用 backtrack() 之前先将nums数组排序
        output = []
        n = len(nums)
        for k in range(n + 1):
            backtrack()
        return output
```

总结：之前一直在for架构下，在选择之前想办法做判断，试了很多次都不成功，原来要修改的地方在“退出回溯 撤销选择”之后。  



**方法二、循环迭代**  

相较于**78题**的区别是：

1、循环开始前先对 `nums` 进行排序  
2、判断当前数字和前一个数字是否相似  
2.1、如果和前一个数字一样，就在前一次循环产生的增量数组 `tmp` 上添加。  
2.2、如果和前一个数字不一样，就在前一次循环产生的结果 `output` 上添加。  

拙图见谅

![QQ图片20200320214359.jpg](https://pic.leetcode-cn.com/ed5e83d3ba64584b08cf086162afdb2b6501791cee5afafccb0e09e2b1f14686-QQ%E5%9B%BE%E7%89%8720200320214359.jpg)


78题代码  

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        output = [[]]
        for num in nums:
            output += [curr + [num] for curr in output]
        return output
```

90题代码

```python
class Solution3:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        if not nums: return []
        output = [[]]
        nums.sort()
        tmp = []
        for i in range(len(nums)):
            if i > 0 and nums[i - 1] == nums[i]:  # 如果和前一个数字一样
                tmp = [curr + [nums[i]] for curr in tmp]  # 就在前一次循环产生的增量数组 tmp 上添加。
            else:  # 如果和前一个数字不一样
                tmp = [curr + [nums[i]] for curr in output]  # 就在前一次循环产生的结果 output 上添加
            output += tmp
        return output
```