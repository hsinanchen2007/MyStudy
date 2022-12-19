### 解题思路
小白一枚，来LeetCode独立解出的第一题，斗胆来分享一下：
简单的遍历算法，在字符串后＋结束符'&'，构成临时字符串temp，另建立一个压缩字符串的字符串空头tS=''，用于一会儿连接压缩字符串。然后进行字符串遍历，将每一个字符与其相邻的后一个字符进行比较，如果相同则循环继续并记录循环次数，直至找到两个不一样的字符。在此处，将之前的相同字符串和计数值连接到压缩字符串头后面，以此类推。直至原字符串S的最后一个字符与我们加的结束符'&'相比较后（PS：原字符串内只含有字母a-z，不含我们设置的结束符。），完成最后一次压缩字符串的连接。
最后，比较压缩字符串与原字符串的长短，输出较短的字符串。over
![1.PNG](https://pic.leetcode-cn.com/c84aba69abf66e862cee7b7154aec055b95363c0bbff06d26742a8747209485b-1.PNG)
### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        temp=S+'&'
        n=1
        tS=''
        for i in range(len(S)):
            if temp[i]==temp[i+1]:
                n+=1
            else:
                tS=tS+temp[i]+str(n)
                n=1
        if len(tS)<len(S):
            return tS
        else:
            return S
```