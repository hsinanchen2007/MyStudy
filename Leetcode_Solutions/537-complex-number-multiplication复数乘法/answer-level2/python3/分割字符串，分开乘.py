### 解题思路
1.根据公式(a+bi)(c+di)=(ac-bd)+(bc+ad)i
2.分开输入字符串，分成a,b,c,d
3.根据公式运算

### 代码

```python3
class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        #分割字符串
        numble = a.split('+')
        numble2 = b.split('+')
        numble3 = []
        #规范字符格式删除最后一个字符'i'，方便进行运算
        numble[1] = numble[1].rstrip('i')
        numble2[1] = numble2[1].rstrip('i')
        #(a+bi)(c+di)=(ac-bd)+(bc+ad)i
        numble3.append(str(int(numble[0])*int(numble2[0])-int(numble[1])*int(numble2[1])))
        numble3.append(str(int(numble[1])*int(numble2[0])+int(numble[0])*int(numble2[1])))
        #合并成字符串输出
        return '+'.join(numble3) + 'i'
```