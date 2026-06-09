### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:

    def longestPalindrome(self, s: str) -> str:
        a = [[False for i in range(len(s))] for j in range(len(s))]
        max_str = ""   # 
        max_num = 0
        for r in range(len(s)):  #卡点3：边界找不对，应该明晰物理含义，意思是从开始下标出发一直到现在的下标，r是右端的下标，l是左端的下标，
            for l in range(r+1): # 卡点1：在还不知道  2:3的时候  需要判定 1:4的时候卡住了，不知道遍历顺序
                # if r == l: # 这个就有问题，根本不是终止
                #     a[l][r] = True 
                # else:
                if s[l]==s[r] and (r-l<=1  or a[l+1][r-1] ):  # 卡点1解答：现在明白了，应该是从 l:r  是从 r向l遍历, 此时遍历 r的时候 r-1全部都遍历过了，所以没有问题
                    # 卡点2：终止条件没找对，最优子结构找到了,  终止条件应该是 r-l<=1
                    a[l][r] = True
                    if r-l+1 > max_num:
                        max_num = r-l+1
                        max_str = s[l:r+1]
        return max_str




            

```