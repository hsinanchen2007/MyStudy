### 解题思路

我这里只算是 标准写法，增加了进位变量。 题解区有很多简洁巧妙的解法。


### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        add_in = 1
        for i in range(len(digits)-1, -1,-1):
            val = digits[i] + add_in
            if val == 10:
                digits[i] = 0
                add_in = 1
            else:
                digits[i] = val
                add_in = 0
                break
                
        if add_in == 1:
            new_nums = [0]*(len(digits)*+1)
            new_nums[0] = 1
            new_nums[1:] = digits
        else:
            new_nums = digits
        return new_nums

```
``` python3 新的更简洁的代码
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        l = len(digits)
        
        for i in range(l-1, -1,-1):
            if digits[i]<9:
                digits[i] += 1
                return digits   # 直接从中间返回，跳出
            else:
                digits[i] = 0
        
        # 若没有跳出，说明必然是连续 9 序列       
        new_digits = [0]*(l+1)
        new_digits[0] =1

        return new_digits