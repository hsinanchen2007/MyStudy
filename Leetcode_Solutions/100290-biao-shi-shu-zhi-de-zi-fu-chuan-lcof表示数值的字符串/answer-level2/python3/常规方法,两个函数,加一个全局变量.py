### 解题思路
![image.png](https://pic.leetcode-cn.com/3cc2dae1673102df8d77e776b8592d476ea726650d08a6cb41b0b39394644463-image.png)
![image.png](https://pic.leetcode-cn.com/bb876fc025cefb35c3fcbe1d2d4ec053e38d2fbdb58342eb0bf5eabd85419625-image.png)
下面的**测试用例**可以使用,注意设置全局变量就可以
"+.e8" false
"1e" false
"0." true
"-." false
".e1" false
"+.8" true
"." false
"+E3" false
".e3" true
### 代码

```
class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.strip()
        n = len(s)
        if n == 0:
            return False
        global num_seem #全局变量判断小数点前面是否有数字
        num_seem=False

        def scan_num(strs):
            global num_seem  # 定义函数中的全局变量
            while strs and 48 <= ord(strs[0]) <= 57:
                global num_seem
                num_seem=True
                strs = strs[1:]
            else:
                return strs

        def scaninteger(strs):  # 扫描'+'和'-'
            if strs and (strs[0] == '+' or strs[0] == '-'):
                strs= strs[1:]
            if strs:  # 应对'e+'情况,即符号去掉后面空了
                return scan_num(strs)
            else:
                return False

        s = scaninteger(s)  # 先扫描有无正负号
        if s and s[0] == '.':
            s = s[1:]
            if s and s[0] == 'e' and num_seem==False:  # 应对".e1"情况 and后面应对'1.e3'
                return False
            if s=='' and num_seem==False: #应对'0.'这种情况,设置了num_seem表示前面是否有数字这种情况
                return False
            s = scan_num(s)
        if s and (s[0] == 'e' or s[0] == 'E') and num_seem==True:
            s = s[1:]
            if s == '':  # 应对'1e'这种情况出现
                return False
            s = scaninteger(s)
        if s == '':
            return True
        return False
```