### 解题思路
此处撰写解题思路
遍历字符串，当遇到1时跳过后一个 即0的位置为1 下一次循环直接从2的位置开始，记录下‘0’值的位置 跑完循环后‘0’值的位置等于len(bits)-1 时返回True
### 代码

```python3
class Solution:
    def isOneBitCharacter(self, bits):
        lens=0
        bit=0
        while lens<len(bits):
            if bits[lens]==1:
                lens +=2
            else:
                bit=lens
                lens +=1
        return bit==len(bits)-1
```