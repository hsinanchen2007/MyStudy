### 解题思路
面向case编程。python中二进制数前加0b。

### 代码

```python3
class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        length = len(data)
        i=0
        while i<length:
            x = data[i] & 0b11111000
            if x < 0b10000000: #一字节
                i+=1
            elif 0b11000000<=x<=0b11011000: #二字节
                if i+1<length and (data[i+1] & 0b11000000)==0b10000000:
                    i+=2
                else:
                    return False
            elif 0b11100000<=x<=0b11101000: #三字节
                tmp = i+1
                while tmp<i+3:
                    if tmp<length and (data[tmp] & 0b11000000)==0b10000000:
                        tmp+=1
                    else:
                        return False
                i=tmp
            elif x == 0b11110000: #四字节
                tmp = i+1
                while tmp<i+4:
                    if tmp<length and (data[tmp] & 0b11000000)==0b10000000:
                        tmp+=1
                    else:
                        return False
                i=tmp
            else:
                return False
        return True    

```