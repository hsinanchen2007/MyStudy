## 思路:

**思路一:** 模拟加法过程

```python
class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1
        for i in range(len(digits)-1, -1, -1):
            carry,b = divmod(digits[i] + carry, 10)
            digits[i] = b
        if carry:
            digits.insert(0, 1)
        return digits
```

**思路二:**

其实不需要这么麻烦,只要判断这位数字是否小于9就行了

```python [1]
class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        for i in range(len(digits)-1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits
            else:
                digits[i] = 0
        return [1] + [0] * len(digits)
```



```java [1]
class Solution {
    public int[] plusOne(int[] digits) {
        for (int i = digits.length - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            } else digits[i] = 0;
        }
        int[] res = new int[digits.length + 1];
        res[0] = 1;
        return res;
     
    }
}
```


