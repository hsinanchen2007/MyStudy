### 解题思路
最小子回文分为两种
- aa型
- bcb型
所有较长回文子串均是以上两种类型的左右相等延长，即 daad、gfbcbfg
对于较长类型的字符串，只需一次迭代找出所有两种类型的子串，放入容器
迭代每个子串，两端相等则延长，两端不等则结束，此时这个延长串就是局部最大子串
最后处理好编辑问题

### 代码

```python3
class Solution:
    
    def longestPalindrome(self, s: str) -> str:
        end = len(s)
        if end in(0,1): return s
        return_str = s[0]  #给定初始值，如无子串，则为第一个元素
        huiwen_small = []

        for i in range(end):
            if s[i] == s[i+1]:huiwen_small.append([i,i+1])  #  **aa**型子串
            if end - i == 2:break                           #至少三个字符构成后面的子串
            elif s[i] == s[i+2]:huiwen_small.append([i,i+2])#  **cbc*型子串

        for item in huiwen_small:
            left = item[0]
            right = item[1]
            while s[left] == s[right]:          #两端相等，继续延长
                if left == 0 or right == end-1: #触顶返回
                    break
                left = left-1
                right = right+1

            if s[left] != s[right]:             #两端不等，缩短回源
                left = left+1
                right = right-1

            if right+1-left>len(return_str):return_str = s[left:right+1]  #循环中的子串较长，则更新将要返回的值
        return return_str
            
            
            
            
            
            
            
            
        
        
            
            
            
            
            
            
            
        
        
        
        
        
        
        
        
```