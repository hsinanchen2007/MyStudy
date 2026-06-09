思路：
1、拿到字符串总长x；
2、因为偶数个字符串一定能全部组成回文，但是奇数个字符须减去一个字符变成偶数个字符才可继续组成回文，当然，有且仅有一个奇数个字符时也是可以的；
3、找出一共有h个奇数个字符，如果h=0，说明全部都可以组成回文，函数返回x；否则，可以组成回文的最长数量就是x-h+1，+1是保留一个奇数个字符；

class Solution:
    def longestPalindrome(self, s: str) -> int:
        sa=set(list(s))
        x=len(s)
        y=h=0
        for i in range(len(sa)):
            y=s.count(sa[i])
            if (y%2)!=0:
                h+=1
        return x-(h-1) if h>=1 else x