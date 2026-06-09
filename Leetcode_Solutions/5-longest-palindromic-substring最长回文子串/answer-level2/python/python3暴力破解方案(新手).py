首先python具有的字符串特性str.[::-1]可以把字符串倒序排列, 所以我们可以很轻松的获得倒序排列之后的字符串, 这样就很容易得到当前字符串是否是回文字符串

第一步我们先判断输入的字符串是否为空字符串, 如果是就直接返回了
然后我们用len方法获取字符串的长度
再用一个变量来保存子字符串
记录首字符的位置

因为我们要找最长的回文字符串, 所以我们从最长的开始查
当查到回文字符串的时候就停止查询, 那么当前字符串就是最长的了

开始判断当前字符串是否是回文字符串, 如果是则直接返回
如果不是, 判断当前子字符串的位置是否已经取到父字符串的末尾, 如果是, 则位置重新置0, 子字符串长度-1,
如果不急, 则pos+1 继续往后取, 直到获得回文字符串, 跳出循环返回

举个例子: s=‘123443567’
我们就先判断s是不是回文, 不是我们就取pos=0, length = 8, 判断 ‘12344356’ 是不是
pos+length < len(s) 则 pos + 1 判断‘23443567’是不是
这时候 pos+length=len(s)了 pos置0,length-1, 再去判断‘1234435’, ‘2344356’, ‘3443567’....
直到找到‘3443’
如果字符串中没有回文,那么当length = 0时 ‘’==‘’[::-1]是成立的, 就会返回空字符串‘’,跳出循环
![image.png](https://pic.leetcode-cn.com/325f0b3f59a014476196389eca7178fbf081ab8539afdb69339fa92dc73ea11c-image.png)


代码如下
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return s
        length = len(s)
        ss = s
        pos = 0
        while ss != ss[::-1]:
            if pos + length == len(s):
                pos = 0
                length -= 1
            else:
                pos += 1
            ss = s[pos: pos+length]
        return ss
            
```
