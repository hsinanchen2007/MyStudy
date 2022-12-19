大概思路就是先把两个str变得一样长,不够位的前面补零,然后倒序遍历任意一个str长度(因为都一样长了),
用索引把a,b字符串中的元素进行相加减,因为是str格式,这边我是用字典转整型,用int也行,我怀疑时间会久一些,pi是向前进位的值,a[str] + b[str] + pi 的和取值[0,1,2,3],取余判断是奇数还是偶数,地板除得出是否需要向前进位,最后还需要判断是否溢出,尽量不用内置方法,如有更好的算法,欢迎指正
```
def addBinary(self, a: str, b: str) -> str:
        sum = ""
        bi = 0
        ab = len(a) - len(b)
        it = {"1":1,"0":0}
        if ab < 0:
            a = "0" * (-ab) + a
        else:
            b = "0" * ab +b 
        for k in range(len(a)-1,-1,-1):
            sum_count = it[a[k]] +it[b[k]] + bi
            bi = sum_count // 2
            if sum_count % 2:
                sum = "1" + sum
            else:
                sum = "0" + sum
        if(bi):
            sum = "1" + sum
        return sum
```
