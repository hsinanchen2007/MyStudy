```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        a = s
        b = '#'
        c = b.join(a)    
        d = list(c)
        d.insert(0, '#')
        d.append('#')
        m_s = ''.join(d)
        record_dict = {}
        max_len = 0
        for i in range(len(m_s)):
            pos = 0
            length = -1
            while i-pos >= 0 and i+pos <= len(m_s) - 1:
                if m_s[i-pos] == m_s[i+pos]:
                    length += 1
                    pos += 1
                else:
                    break
            record_dict[length] = i
            max_len = max(max_len, length)
        output = m_s[(record_dict[max_len]-max_len):(record_dict[max_len]+max_len)]
        output = output.replace('#', '')
        return output
```

'''
马拉车算法
细节：1. python如何从'aa'变'#a#a#'的处理
2. 计算的是扩散了多长而非包括中心点有多长，因此length从-1开始
3. while判定的小细节，日常len()-1
4. while里的pos不能放外面，且一旦不符合就break
5. strip只有头尾，replace才是去除全部
'''