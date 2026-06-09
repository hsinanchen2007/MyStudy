### 解题思路
先建表，这里也可以用collections模块里面的Counter
再遍历表的值，如果大于2的话就直接整除2就可以构成回文了，再乘2就是回文的数目了
这就找出了所有的偶数对，如果排序偶数对还存在其他元素，最长就是偶数对加上中心元素，
如果字符串元素本身就成对出现，就没有其他元素了，就直接返回字符串长度。
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        str_map=dict()
        for i in s:
            if i in str_map:
                str_map[i]+=1
            else:
                str_map[i]=1
        ans=0
        for v in str_map.values():
            if v>=2:
                ans+=(v//2)*2
        return ans+1 if len(s)>ans else len(s)

```