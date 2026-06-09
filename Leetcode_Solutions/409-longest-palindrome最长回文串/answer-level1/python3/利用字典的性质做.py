### 解题思路
如果可以形成回文，那么必然是出现了两次以上。

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        letter_dict={}
        suros_num=0
        for l in s:
            if l in letter_dict.keys():
                letter_dict[l]+=1
            else:
                letter_dict[l]=1
        if_add=0
        for k in letter_dict.keys():
            if letter_dict[k]%2==0:
                suros_num+=letter_dict[k]
            else:
                suros_num+=letter_dict[k]-1
                if_add=1
        suros_num+=if_add
        return suros_num


```