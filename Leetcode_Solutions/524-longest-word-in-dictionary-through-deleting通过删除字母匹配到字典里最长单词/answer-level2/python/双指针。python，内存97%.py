### 解题思路
题目的“字典顺序中的最小字符串”其实是指字符串对应的ASCii码，py可以直接使用min()函数来进行判断
所谓双指针，无非就是在比较A是否为B的子字符串时，从A的第一个元素开始，从左到右地逐一拿出B的元素，如果相等，则A的元素往右移动一个，B的元素的也要往右……

### 代码

```python
class Solution(object):
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        ##double pointer
        if len(s)==0:return ''
        Out=''
        def isSub(vlu):
            idx=-1
            for per in vlu:
                while True:
                    idx+=1
                    if idx==len(s):return False
                    if s[idx]==per:break              
            return True 
        for per in d:
            if isSub(per):
                if len(per)==len(Out):Out=min(per,Out)
                if len(per)>len(Out):Out=per
                # tmpLen=max(tmpLen,per,key=len)
        return Out

```