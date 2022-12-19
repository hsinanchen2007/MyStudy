### 解题思路
首先将字符串中所有的字符取出来，对应字典中的值进行累加，之后对每一个I搜寻右边是否有V,X,每一个X右边是否有L,C，每一个C右边是否有D，M,每找到一个对应I的字符sum-2,每找到一个x对应的字符sum-20，每找到一个C对应字符sum-200，对字符串遍历时只遍历前n-1个字符，最后一个字符直接转化为数字后与sum相加。

### 代码

```python
class Solution(object):
    def romanToInt(self,s):
        """
        :type s: str
        :rtype: int
        """
        sum=0
        sum_i=0
        sum_x=0
        sum_c=0
        dict_1={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        roman_list=list(s)
        for i in range(len(roman_list)-1):
            sum+=dict_1[roman_list[i]]
            if roman_list[i]=='I':
                if roman_list[i+1]=='V' or roman_list[i+1]=='X':
                    sum_i=sum_i+1
            if roman_list[i]=='X':
                if roman_list[i+1]=='L' or roman_list[i+1]=='C':
                    sum_x=sum_x+1
            if roman_list[i]=='C':
                if roman_list[i+1]=='D' or roman_list[i+1]=='M':
                    sum_c=sum_c+1
        sum=sum-sum_i*2-sum_x*20-sum_c*200+dict_1[roman_list[-1]]
        return sum
           
```