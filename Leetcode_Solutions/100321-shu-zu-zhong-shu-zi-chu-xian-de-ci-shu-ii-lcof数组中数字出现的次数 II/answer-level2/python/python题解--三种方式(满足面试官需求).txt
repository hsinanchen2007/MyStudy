### 1.排序后在查找
![image.png](https://pic.leetcode-cn.com/783533fd7f543d67e116841b77c20cd7d32e0357995dff7bbfccd7a3a6d932f7-image.png)
1. 先将数组排序
2. 判断当前位置的数字是否和前后数字相等,如果不相等则直接返回
- 这个方法需要在开始和结尾的特殊情况考虑进去
- 时间复杂度`O(nlogn)`,空间复杂度`O(1)`

### 代码

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        length = len(nums)
        if nums[0] != nums[1]:
            return nums[0]
        for i in range(1, length-1):
            if nums[i] != nums[i-1] and nums[i] != nums[i+1]:
                return nums[i]
        return nums[length-1]

```
### 2.使用哈希表
![image.png](https://pic.leetcode-cn.com/dcb35e4a35dcbf576fa340bf9da859bf53f56765e6a687db0ea1b31b17374ccb-image.png)

1. 首先遍历一次数组,将每个数字出现的次数存储到哈希表中
2. 查找哈希表中仅出现一次的数字
- 时间复杂度`O(n)`,空间复杂度`O(n)`
### 代码
```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dic = {}
        for i in nums:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1       
        for i,j in dic.items():
            if j == 1:
                return i

```

### 3.二进制的各位相加
![image.png](https://pic.leetcode-cn.com/387ce96d0ac7799f6cef82866b95bec9adc9aaf11f5ad0b1b439e1315de18264-image.png)

- 我们想一下如果一个数字出现三次,那么他的二进制位表示的每一位(0或1)也出现了三次.如果把所有出现三次的数字的二进制表示的每一位都分别加起来,那么每一位的和都能被3整除
- 我们把所有数字的二进制位的每一位加起来.若果某一位的和能被3整除,那么那个只出现一次的数字二进制表示中对应的那一位为0,否则为1

- **步骤:**
1. 统计所有数字二进制位的和
2. 判断每一位的和能否被3整除,求解最后结果
- 时间复杂度`O(n)`,空间复杂度`O(1)`(常数空间))
### 代码
```
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        bitSum = [0] *32 #定义存储各个位的数组

        for i in nums: #统计各位之和
            mask = 1
            for j in reversed(range(32)):
                if mask & i:
                    bitSum[j] += 1
                mask = mask << 1

        result = 0
        for i in range(32):#得到最终结果
            result = result << 1
            result += bitSum[i] % 3

        return result
        

            


```
