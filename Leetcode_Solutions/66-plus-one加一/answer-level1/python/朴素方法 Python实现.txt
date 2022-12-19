### 解题思路
朴素方法
①最低位加上1
②从最低位向次高位遍历，若有某位>9（在本例中只可能为10），则将其置为0，并将其高一位加一
③检查最高位，若>9，则将其置为0，并拓展一位最高位，新的最高位置为1

另，转int再转字符串的方法，可能由于位数过大超出int上限，朴素方法不会出现该问题
### 代码

```python
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        digits[-1]+=1;
        for i in range(-1,0-len(digits),-1):
            if digits[i]>9:
                digits[i]=0
                digits[i-1]+=1
        if digits[0]>9:
            digits[0]=0
            digits=[1]+digits
        return digits


```