### 解题思路2
优化的滑动窗口法，将解法1中用list改成用hashmap，将查找时间复杂度从O(n)降为O(1)。

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dic={}
        max_len=0
        cur_len=0
        ignore_str_index_end=-1
        for i,ss in enumerate(s):
            if ss in dic and dic[ss]>ignore_str_index_end:
                cur_len=i-dic[ss]
                ignore_str_index_end=dic[ss]
                dic[ss]=i
            else:
                dic[ss]=i
                cur_len+=1
            if cur_len>max_len:
                max_len=cur_len
        return max_len
```
### 解题思路1
滑动窗口法

### 代码
```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        lst_str=[]
        max_len=0
        cur_len=0
        
        for i in s:
            if i not in lst_str:
                lst_str.append(i)
                cur_len+=1
                
            else:
                index=lst_str.index(i)
                lst_str=lst_str[index+1:]
                lst_str.append(i)
                cur_len=len(lst_str)
            if cur_len > max_len:
                max_len=cur_len
        return max_len
```

