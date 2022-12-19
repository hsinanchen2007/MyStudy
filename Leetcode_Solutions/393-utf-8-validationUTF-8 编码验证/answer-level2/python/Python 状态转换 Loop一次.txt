### 解题思路
主要思路就是在Loop经过Data时，在每一步要求明确自己所在的state，是either 1）准备进入下一个新的字符 或者 2）已经在1个字符里，正在验证编码真伪

### 代码

```python
class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        def transform(integer):
            binary = (bin(integer)[2:])
            while len(binary) < 8:
                binary = "0"+binary
            if len(binary) > 8:
                binary = binary[-8:]
            return binary

        binary_str = [transform(integer) for integer in data]
        state = 0 # 0 means beginning of a data, 1 means within the data
        word_len = 0
        
        for data in binary_str:
            if state==0:
                if data[0]=='0': # 1 byte data
                    state = 0
                    word_len = 0
                    continue
                else:
                    word_len = 0
                    i = 0
                    while data[i] == '1' and i<= len(data)-2:
                        word_len +=1
                        i += 1
                    if not (2<= word_len<=4):
                        return False
                    if not (data[i] == '0'):
                        return False
                    word_len -=1
                    state = 1
            else: #state==1 in a word right now
                if not (data[0]=='1' and data[1]=='0'):
                    return False
                word_len -= 1
                if word_len==0:
                    state= 0
        print("Remaining Word len = ",word_len)
        if word_len == 0:
            return True
        else:
            return False
                
        
        
    
                  
```