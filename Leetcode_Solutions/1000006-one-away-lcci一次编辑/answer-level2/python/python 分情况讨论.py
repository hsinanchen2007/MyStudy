具体分为两大分支来处理：

字符串长度相同 -> 遍历一遍找出不同等的字符，如果超过1次不同，则返回False
字符串长度不同 -> 遍历，长的字符串丢下一个字符与另外一个字符串比较，如果相同就返回True
```
class Solution(object):
    def oneEditAway(self, first, second):
        """
        :type first: str
        :type second: str
        :rtype: bool
        """
        
        # 具体分为两大分支来处理：

        # 字符串长度相同 -> 遍历一遍找出不同等的字符，如果超过1次不同，则返回False
        # 字符串长度不同 -> 遍历，长的字符串丢下一个字符与另外一个字符串比较，如果相同就返回True

        if len(first)==len(second):#替换字符
            diff=0
            for i in range(len(first)):
                if first[i]!=second[i]:
                    diff+=1
                    if diff>1:
                        return False
            if diff<=1:
                return True
        if abs(len(first)-len(second))==1:#插入/删除字符
            if len(first)>len(second):
                longer=first
                shorter=second
            else:
                longer=second
                shorter=first
            for i in range(len(shorter)):
                j=i
                if longer[j]!=shorter[i]:
                    j+=1
                    if longer[j]!=shorter[i]:
                        return False
            return True
        return False
```



