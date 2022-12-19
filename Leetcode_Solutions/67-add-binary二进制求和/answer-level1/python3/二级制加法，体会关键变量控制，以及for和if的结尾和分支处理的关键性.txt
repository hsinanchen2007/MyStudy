### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # 二进制加法
        # 最为关键的就是控制几个变量的变化，进位,处理这个字符串中每一个位变化后的结果
        # 结尾前的处理，这也是通常要注意的
        n = 0
        num = int(a) + int(b)
        res = list(str(num))
        print(res)
        n = 0
        for i in range(-1, -1-len(res),-1):
            if (int(res[i])+n) >=2:
                res[i] = (int(res[i])+n)%2 
                n = 1
            else:
                res[i] = int(res[i])+n
                n = 0
        if n == 1:
            res.insert(0,1)
        f = ""
        for i in res:
            f+=str(i)
        return f



```