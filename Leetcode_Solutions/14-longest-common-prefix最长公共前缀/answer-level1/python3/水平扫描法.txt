### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if  strs == []:  # 若为空列表，直接返回''
            return ''
        else:
            num_strs = len(strs)  #strs 列表中字符串的数量
            len_str0 = len(strs[0])  #strs 列表第一个字符串长度 
            repeat_str = [] #用于存储重复的字母
            for i in range(len_str0): #从字符串strs[0]的第一个字母循环到最后一个字母，最长重复子串不会超过这个数 
                for j in range(num_strs): #遍历其他字符串，需要从第一个字符串开始检查用于兼容strs只有一个字符串的情况
                    # 限制条件1为判断i 是否超过strs[j]的长度；限制条件3用于判断是否完成遍历，完成遍历且相等则记录该位置字母
                    if i< len(strs[j]) and strs[j][i] == strs[0][i] and j == num_strs-1: 
                        repeat_str.append(strs[j][i])
                    elif i< len(strs[j]) and strs[j][i] == strs[0][i]: # 该语句用于未遍历完，但该位置字母一致的情况
                        continue
                    else:   # 其他情况表明在i 位置字母不相同，直接return 结果，函数结束
                        return ''.join(repeat_str)
            return ''.join(repeat_str) # 该语句只在strs[0]是最长子串时才会执行
```