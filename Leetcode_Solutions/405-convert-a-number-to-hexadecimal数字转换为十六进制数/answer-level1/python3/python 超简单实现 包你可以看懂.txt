正数转为16进制相信大家都非常容易实现，难点在于负数永补码m表示的
本文的思想就是将负数的补码转化为正数再进行16进制的变换

    def toHex(self, num: int) -> str:
        if num==0:
            return '0'
        
        if num<0:
            max_int = 0xffffffff + 0x00000001
            num+=max_int
        
        list1=['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f']
        s =''
        while num!=0:
            a = num%16
            s = list1[a]+s
            num//=16
            
        return s