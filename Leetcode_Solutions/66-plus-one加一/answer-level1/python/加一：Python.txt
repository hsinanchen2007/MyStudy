### 解题思路
逆序遍历数组，逐为判断+1后是否需要进位，不需要则直接该位+1，返回数组，需要则将该位置为0（因为是+1），进行下一次循环继续判断高位+1。
若是循环完毕未返回结果，则代表是[9], [9, 9]此类数组，此时数组各位都为0，只需要在数组头插入数字1即可。

### 代码

```python
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        i = len(digits) - 1
        while(i >= 0):
            # 判断当前位+1是否等于10进位，因为是+1，当前位进位后必为0，进行下一次循环高位+1
            if digits[i] + 1 == 10:
                digits[i] = 0
                i -= 1
            # 不需要进位，直接修改该位，返回数组
            else:
                digits[i] += 1
                return digits
        # [9], [9, 9]此类进位需要扩展数组，插入首位1
        digits.insert(0, 1)
        return digits
```