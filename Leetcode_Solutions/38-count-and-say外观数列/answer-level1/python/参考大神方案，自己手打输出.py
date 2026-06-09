### 解题思路
递归方法中：
temp=self.countAndSay(n-1)+'a'是关键，
1. 递归调用上一个报数
2. 之所以在上一个报数结尾加有一个非数字的字符，用于判断上一个报数的最后一位数字是否与倒数第二位数字相同，
假如没有最后一个非数字字符的话，temp= self.countAndSay(n-1),当for最后一次循环的i=len(temp)-2时，若temp[i]==temp[i+1],count+=1,但是temp[i+1]的值没有读取，导致最后一组判断没有加入到result中；若temp[i]!=temp[i+1],则temp[-1]没有加到result中；


### 代码

```python
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n==1: return '1'

        count = 1
        temp = self.countAndSay(n-1)+'a'
        temp = list(temp)
        result = ''
        for i in range(len(temp)-1):
            if temp[i]==temp[i+1]:
                count+=1
            else:
                result +=str(count)+temp[i]
                count = 1
        return result


```