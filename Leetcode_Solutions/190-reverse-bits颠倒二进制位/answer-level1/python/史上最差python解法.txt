        res = bin(n)[2:] #将n转换成2进制形式，并且去除前缀0b
        res = res.zfill(32)#在二进制左侧填充0，使得长度为32位
        res = res[::-1]# 反转二进制
        return int(res,base=2)#将二进制转换为整数