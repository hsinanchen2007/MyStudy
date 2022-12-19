### 解题思路
见代码注释，原理可参考https://blog.csdn.net/qq_37969433/article/details/82947411#commentBox

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        '''
        思路：KMP算法：首先求出next数组，然后根据next数组进行匹配
        说明：子串为模式串，在这里指needle，主串为haystack
        '''
        def get_next(s):
            '''求next数组，原理可参考https://blog.csdn.net/qq_37969433/article/details/82947411#commentBox'''
            len_s = len(s)
            next_array = [-1] * len_s
            i = 0  # 指向主串的指针
            j = -1  # 指向子串的指针

            while i < len_s-1:  # 注意-1
                '''当子串与主串完全不匹配或者子串当前字符与主串当前字符匹配'''
                if j == -1 or s[i] == s[j]:  
                    i += 1
                    j += 1
                    next_array[i] = j  # next[0]规定为-1，从next[1]始终等于0，实际上从next[2]开始求解
                else:
                    j = next_array[j]  # 子串当前字符与主串当前字符不匹配，根据之前求得的next数组，将j回溯到指定位置
            
            return next_array

        def kmp_index(haystack, needle):
            '''根据next数组进行匹配'''
            len_h = len(haystack)
            len_n = len(needle)
            if len_n == 0: return 0
            i = 0
            j = 0
            next_array = get_next(needle)

            while i < len_h and j < len_n:
                if haystack[i] == needle[j]:
                    i += 1 
                    j += 1
                else:
                    j = next_array[j]  # j指针回溯,i指针不回溯
                '''j==-1表示子串的第一个字符与主串当前位置不匹配
                然后i加1（指向主串下一个字符）,j变为0（指向子串第一个字符）'''
                if j == -1:
                    i += 1
                    j = 0

            if j == len_n:
                return i - j
            return -1

        return kmp_index(haystack, needle)

```