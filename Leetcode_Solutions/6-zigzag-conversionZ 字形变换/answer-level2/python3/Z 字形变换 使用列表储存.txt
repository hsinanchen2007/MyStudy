开辟numRows个（记为n）列表，按照1，2，…………n-1,n,n-1…………2的顺序依次将字符串中的数据添加到对应列表，全部添加完毕后依次读出列表中的字符串即可

```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows<2:                       #行数为1时很特殊，直接输出即可
            return s
        Datas = list()
        for i in range(numRows):            #新建列表
            datas = []
            Datas.append(datas)
        num = 0
        while(num<len(s)):                  #循环压入
            for i in range(numRows*2-2):
                if i<numRows:
                    Datas[i].append(s[num])
                else:
                    Datas[2*numRows-2-i].append(s[num])
                num+=1
                if num>=len(s):
                    break
        s = ''
        for i in range(numRows):
            s += ''.join(Datas[i])          #列表元素转化为字符串
        return s
```
