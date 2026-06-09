### 思路：
1、如果本身就是回文字符串，直接return True
2、首尾两个指针，判断首尾指针处的字符是否相等，
    2.1、如果相等：直接进行下一次的判断，左指针向右，右指针向左
    2.2、如果不等：
        2.2.1、先删除左边当前字符，看剩下是否相等:相等就return True，不等就转2.2.2
        2.2.2、再删除右边当前字符，看剩下是否相等：相等就reurn True,不等就整体return False，因为此时左边和右边的字符串都尝试删除过了
3、注意事项：不同用s.replace(old,new,1)方法：因为会替换掉s中第一次出现的字符,而不是当前的字符，eg:s = abba  你想替换最后一个a,其实它会替换第一个a,同时，**replace方法并不会改变原来s的值，而是返回一个新对象**。所以最好用切片的方式最靠谱！
### 代码:
```
class Solution:
    def validPalindrome(self, s: str) -> bool:
        n = len(s)
        i,j=0,n-1
        ##方法二：双指针，一头一尾两个指针，因为回文字符的特性来判断是否删除
        if s==s[::-1]:  ##本身就是回文字符串
            return True
        else:
            for m in range(n):
                if s[i]==s[j]:
                    i+=1
                    j-=1
                else:
                    #先删除左边
                    s_L = s[:i]+s[i+1:]
                    # print("s_L:",s_L)
                    if s_L==s_L[::-1]:
                        return True
            
                    s_R = s[:j]+s[j+1:]
                    # print("s_R:",s_R)
                    if s_R==s_R[::-1]:
                        return True
                    
                    return False
```
