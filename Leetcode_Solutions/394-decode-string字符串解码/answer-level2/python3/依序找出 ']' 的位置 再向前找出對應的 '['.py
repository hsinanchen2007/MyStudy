### 解题思路
依序找出 ']' 的位置 再向前找出對應的 '['
找到對應的[]之後 再確認 '[' 左邊的數字大小
將s此段的文字替代為 N*[]內的文字

### 代码

```python3
class Solution:
    def decodeString(self, s: str) -> str:
        right = 0
        while right < len(s):
            if s[right] == ']':
                left = right
                while s[left] != '[':
                    left -= 1
                target = s[left+1:right]
                
                num = ''
                left_num = left - 1
                while s[left_num].isdigit():
                    left_num -= 1
                num =  s[left_num+1:left] + num    
                
                vec = target * int(num)
                s = s[:left_num+1] + vec + s[right+1:]
                right = left_num + 1 + len(vec)
            else :
                right += 1  
        return s          
                    
                

```