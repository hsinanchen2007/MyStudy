### 解题思路
此处撰写解题思路
双指针
### 代码

```python3
class Solution:
    def validPalindrome(self, s: str) -> bool:
        #双指针
        def helper(s1:str):
            l=0
            r=len(s1)-1
            while l<=r:
                if s1[l]!=s1[r]:
                    return l,r
                l+=1
                r-=1
                if l>r:
                    return l,r
        #第一次判别 
        l1,r1=helper(s)
        if l1>r1:
            return True
        # 当出现有不相等的字符，返回不相等的字符的区间的下标 ，左边部分[a,b]
        l,r=helper(s[l1:r1])
        if l>r:
            return True
        # 右边部分 比如[a,b,c] 放进判别的是[b,c]
        l,r=helper(s[l1+1:r1+1])
        if l>r:
            return True
        return False

 
```