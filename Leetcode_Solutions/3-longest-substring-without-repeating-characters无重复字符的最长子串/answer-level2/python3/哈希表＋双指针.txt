### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    """
    题目分析:
        由于子串是连续的，所以想到利用滑动的窗口+双指针
    思路：
        构建一个hash表，存放已经找到的不重复元素的索引；从头开始找，有重复的则更改l指针，并计算之前的最大长度，再更新最大长度
    @l:左指针
    @r:右指针
    @curr_res:当前子串长度
    @max_res:最大子串长度
    @_dict:hash表,用来快速查找
    
    """
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) < 2:
            return len(s)
        length = len(s)
        l=0
        max_res = curr_res = 0
        _dict = {}

        for r in range(length):
            #如果在里面了
            if s[r] in s[l: r]:
                #计算最大长度
                max_res = max(max_res, curr_res)
                #左指针位置+1
                l = _dict[s[r]]+1
                #重新计算当前长度
                curr_res = r-l+1
                #赋于新的索引值
                _dict[s[r]] = r
            #如果不在里面则添加进去
            else:
                _dict[s[r]] = r
                #当前长度+1
                curr_res += 1
        return max(max_res, curr_res)



```