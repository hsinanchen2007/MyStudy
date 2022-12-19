### 解题思路
对于前面的数小于后面的数，采用先减后加的方法，同时最后一位数恒为加

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        # 对于前面的数小于后面的数，采用先减后加的方法，同时最后一位数恒为加
        dict_ = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        sums = 0
        m = len(s)
        for i in range(m):
            if i != m-1: 
                if dict_[s[i]]<dict_[s[i+1]]:
                    sums -= dict_[s[i]]
                else:
                    sums += dict_[s[i]]
            else:
                sums += dict_[s[i]]
        return sums
```