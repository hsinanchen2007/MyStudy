        思路：
        1.用min(,key=)函数找出strs中最短的字符串（minstr），因为最长公共前缀长度一定不超过最短的字符串长度；
        2.遍历strs，如果str1与minstr相同，跳出此次循环，minstr不变；
        3.如果str1与minstr不一致，用cnt记录两者相同的字母数，在循环中，如果经过第一位比较后不等，一定无公共前缀，即可返回“”；
        如果一次比较后，cnt>0，minstr=minstr[:cnt]
        4.继续遍历，最后返回minstr
        ps：注意防止不练等情况！


```python []
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs)==0:
            return ""
        minstr=min(strs,key=len)
        print minstr
        for str1 in strs:
            if str1==minstr:    
                continue
            cnt=0
            for i in range(0,len(minstr)):
                if minstr[i]==str1[i]:
                    cnt+=1
                if cnt==0:
                    return ""
                if minstr[i]!=str1[i]:#防止不连等的情况
                    break
            minstr=minstr[:cnt]
        return minstr
```
