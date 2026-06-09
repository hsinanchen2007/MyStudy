- 注意考虑首位进位的边界问题
~~~
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits[-1] +=1
        for i in range(len(digits)-1, -1, -1):
            if digits[i] != 10:
                return digits
            elif digits[i] == 10 and i>=1:
                digits[i] = 0
                digits[i-1] += 1
            #当首位需要进位时
            elif digits[i] == 10 and i==0:
                digits[i] = 0
                digits.insert(0,1)
        #若首位进位，则循环不能返回数组
        return  digits
~~~