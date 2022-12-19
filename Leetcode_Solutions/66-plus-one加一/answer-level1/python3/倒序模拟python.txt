### 思路
> 更多LeetCode题解以及面试经验 [Mereder](https://mereder.github.io)

模拟实现过程，并且注意特殊情况，既然是从低位开始+1，则遍历数组需要从后向前。

```python
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if not digits:
            return []
        # 倒序遍历
        index = len(digits)-1
        # 初始化情况
        digits[index] = digits[index]+1
        carry = 0
        while index >= 0:
            # 满足进位条件，则进行进位
            if digits[index]+carry>9:
                digits[index] = (digits[index]+carry)%10 # 模10
                carry = 1
            # 不满足进位，加上可能存在的carry,然后直接退出就可以了
            else:
                digits[index] += carry 
                carry = 0
                break 
            index -= 1
        # 判断是否需要再补入一个1
        if index == -1 and carry ==1 :
            return [1]+digits
        else:
            return digits
```