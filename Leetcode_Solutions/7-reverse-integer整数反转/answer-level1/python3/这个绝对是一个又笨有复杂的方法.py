### 解题思路
让我看看有没有比我还笨的方法······
如何处理负号
如何处理末尾位的0
解决思路：
1. 判断是否大于0，小于0取绝对值，再反转。
2. 判断是末尾有几个0.倒叙查找第一个不是0的位置
### 代码

```python3
class Solution:
    def reverse(self, x):
        if x > 0 :
            x = list(map(int, str(x)))
            x.reverse()
            y = []
            for i in range(len(x)) :
                if(x[i] != 0) :
                    flag = i
                    break
            for j in range(flag, len(x)):
                y.append(x[j])
            x = int(''.join(map(str,y)))
            if x > 2**31:
                return 0
            return x
        elif x == 0:
            return x
        else:
            x = abs(x)
            x = list(map(int, str(x)))
            x.reverse()
            y = []
            for i in range(len(x)) :
                if(x[i] != 0) :
                    flag = i
                    break
            for j in range(flag, len(x)):
                y.append(x[j])
            x = '-' + ''.join(map(str,y))
            if int(x) < (-2**31):
                return 0
            return int(x)
```