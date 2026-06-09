```
class Solution:
    def validPalindrome(self, s: str) -> bool:
        tmp=re.sub(r"[^0-9a-zA-Z]","",s).lower()
        if tmp==tmp[::-1]:
            return True
        n=len(tmp)
        left=0
        right=n-1
        while left<right:
            if s[left]==s[right]:
                    left+=1
                    right-=1
            else:
                s1=s[0:left]+s[left+1:]
                s2=s[:right]+s[right+1:]
                if s1==s1[::-1] or s2==s2[::-1]:
                    return True
                else:
                    return False
```
思路：

a.双指针，因为最多只能删除一次字符，所以当判断有一次不符合之后，继续跳过该字串往下走然后判断
