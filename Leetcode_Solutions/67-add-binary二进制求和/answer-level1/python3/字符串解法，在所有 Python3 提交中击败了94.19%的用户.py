主要想法是把字符串倒置，进位操作会比较方便。
另外用了字典记录加法结果，额外的字符记录进位。
结果还不错
执行用时 :48 ms, 在所有 Python3 提交中击败了94.19%的用户
内存消耗 :13.1 MB, 在所有 Python3 提交中击败了88.38%的用户
```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        add_dict = {
            #第一位和第二位代表来自a，b的两个字符，第三位代表是否有来自前一位加法的进位（即下方的extra）
            "100": '1',
            "101": '10',
            "010": '1',
            "011": '10',
            "000": '0',
            "001": '1',
            "110": '10',
            "111": '11',
            #第一位来自一个字符，第二位来自进位情况（a,b长度不同，其中一个字符串已经遍历完成，另一段没有完成）
            "10": "1",
            "11": "10",
            "00": "0",
            "01": "1",
        }
        #将字符串倒置，最小位就是第一位，从第一位开始往后做加法，如有进位，则用extra记录到后面一位的加法中
        a = a[::-1]
        b = b[::-1]
        sum = ""
        extra = "0"
        #从头遍历两串字符串
        for i in range(max(len(a), len(b))):
            #3种情况，ab均未遍历完成，a未完成b完成，a完成b未完成
            if i < len(a) and i < len(b):
                add = add_dict[a[i] + b[i]+extra]
            elif i < (len(a)):
                add = add_dict[a[i]+extra]
            else:
                add = add_dict[b[i]+extra]
            #处理加法结果add
            #3种结果，add='0'或'1'表示没有进位，add='10'表示有进位且此位的结果为0，add='11'表示有进位且此位的结果为1
            if add == "0" or add == "1":
                sum += add
                extra = "0"
            elif add == "10":
                sum += "0"
                extra = "1"
            else:
                sum += "1"
                extra = "1"
        #若遍历完成，仍有进位，则在结果末尾加1
        if extra == "1":
            sum += "1"
        #最后把结果倒置回来
        sum = sum[::-1]
        return sum
```
