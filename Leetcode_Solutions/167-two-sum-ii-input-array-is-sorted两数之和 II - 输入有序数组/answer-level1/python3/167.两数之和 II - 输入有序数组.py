### 解题思路
双指针，左右各一个指针，大于target右指针左移，小于target左指针右移，等于则返回

哈希表结果：将数组内容存储到哈希表（字典）里再查询。一开始我直接在数组里查询就提示超时了，看来dict确实查询快啊
![image.png](https://pic.leetcode-cn.com/3b65c4d238e926d31d3c6ef32f1c2e8ad6eb078c4387665ac509cc4588a56e90-image.png)

### 代码

```python3
#双指针
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:

        left = 0 
        right = len(numbers) - 1

        while left < right:
            
            if numbers[left] + numbers[right] == target:
                return [left+1,right+1]
            elif numbers[left] + numbers[right] < target:
                left += 1
            else:
                right -= 1

#哈希表
class Solution(object):
    def twoSum(self, numbers, target):
        dict_an = {}
        
        for i,num in enumerate(numbers):
            another_num = target -num
            if another_num in dict_an:
                return[dict_an[another_num]+1,i+1]
            dict_an[num] = i


```