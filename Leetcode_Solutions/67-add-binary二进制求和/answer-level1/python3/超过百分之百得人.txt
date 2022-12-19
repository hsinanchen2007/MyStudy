python中int（）和bin（）函数可以完美解决，思路就是转化为十进制数相加，在转化为二进制数。
代码如下：
def addBinary(self, a: str, b: str) -> str:
        a_=int(a,2)  //转为二进制
        b_=int(b,2)
        return bin(a_+b_)[2:] //以二进制输出
