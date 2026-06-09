主要通过Python内置函数bin()和int(str,进制)进行转换。其中两个整数相加的执行速度优于两个字符串相加
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(bin(int(a,2)),2) + int(bin(int(b,2)),2))[2:]