### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        i = len(digits) - 1
        acc = 1
        while i >= 0:
            if digits[i] + acc > 9:
                digits[i] = 0
                i -= 1
            else:
                digits[i] += acc;
                acc = 0
                i -= 1
        if acc == 1:
            digits.insert(0, 1)    
        return digits;
```

# Java
```
class Solution {
    public int[] plusOne(int[] digits) {
        int i = digits.length - 1;
        int acc = 1;
        while(i >= 0) {
            if (digits[i] + acc > 9) {
                digits[i] = 0;
                i -= 1;
            }
            else {
                digits[i] += acc;
                acc = 0;
                i -= 1;
            }
        }
        if (acc == 1) {
            digits = new int[digits.length + 1]; 
            digits[0] = 1;
        }
        return digits;
    }
}
```
