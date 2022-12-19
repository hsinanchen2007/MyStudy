### 解题思路
首先基本思路其他的题解都说了，如果满足条件，那么str1和str2一定由m和n个公共串构成，例如str1=ABABAB，str2=ABAB,分别由3个AB和2个AB构成，那么str1+str2=str2+str1，ABABAB+ABAB=ABABABABAB=ABAB+ABABAB。
#### 总共三种情况：
1. 两个串长度相同切满足str1+str2=str2+str1，那么肯定本身就是最大公共串，例如ABAB+ABAB=ABAB+ABAB。直接返回其中一个就行了。
2. 不满足str1+str2=str2+str1，不存在公共串，返回空串。
3. 长度不相同且满足str1+str2=str2+str1，那么这种情况就想我们举的例子，ABABAB,ABAB，说明长的那个str1比str2多出了一些公共串，可能是一个两个，总之公共串一定出现在多出来的这一段，那么我们取出来str1=AB,str2不变，再对比这两个串，AB,ABAB,同理str2比str1长，那么公共串一定出现在长的那部分，ok，令str2=AB，str1不变，现在就变成了情况1了，得到结果。


### 代码

```python
class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        if str1+str2!=str2+str1:
            return ""
        
        diff=len(str1)-len(str2)
        if diff ==0:
            return str1
        elif diff>0:
            str1=str1[len(str2):]
        else:
            str2=str2[len(str1):]
        return self.gcdOfStrings(str1,str2)
```