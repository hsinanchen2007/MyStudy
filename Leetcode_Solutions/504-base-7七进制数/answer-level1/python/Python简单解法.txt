### 解题思路
十进制转n进制的规则都是：num一直除以n,直到商为0位置，然后”倒着取余数“
1、对0 特判一下
2、用while循环一直判断商是否为0即可
3、负数也是一样的，只是符号不同
4、在最后一定要取反向的
5、num = num//7:向上取整，不然会出现小数，就不对

### 代码

```

class Solution:
    def convertToBase7(self, num: int) -> str:
        ##十进制转n进制的规则：数字一直除n,直到商变为0为止，然后倒着取余数
        
        if num==0:
            return "0"
        ##先判断一下num的正负
        if num<0:
            flag = 1
            num=-num
        else:
            flag = 0
        res = []
        while num>0:
            yushu = num%7
            res.append(str(yushu))
            num = num//7 ##下一次循环时的num的值就是这次的商,一定是向上取数的整除，不然会出现小数
        if flag:  ##num为负数的话，还要加上符号
            res.append("-")
        ##要倒取余数
        res.reverse()
        return "".join(res)

```