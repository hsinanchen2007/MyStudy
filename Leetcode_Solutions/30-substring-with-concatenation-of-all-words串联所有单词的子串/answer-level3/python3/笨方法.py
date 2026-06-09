### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        
        res = []
        if not words or not s:
            return res


        dw = dict()

        lw = len(words)
        ls = len(s)
        
        lwd=len(words[0])
        all_len = lw*lwd

    
        minLen = len(s)

        for word in words:
            if word in dw.keys():
                dw[word] +=1
            else:
                dw[word] = 1
        real_len = len(dw.keys())        
        left = 0
        right = 0
        match =0
        
        while right < ls-all_len+1:
            tmp = s[right:right+all_len]
            
            window=dict()
            match = 0
            for i in range(0,all_len-lwd+1,lwd):
            
                tmp1 = tmp[i:i+lwd]
                
                if tmp1 in dw.keys():
                #改变窗map的值
                    if tmp1 in window.keys():
                        window[tmp1] += 1
                    else:
                        window[tmp1] = 1
                    
                    if window[tmp1] == dw[tmp1]:
                        match += 1 
            if match == real_len:
                res.append(right)
            right += 1
            
        return res
```