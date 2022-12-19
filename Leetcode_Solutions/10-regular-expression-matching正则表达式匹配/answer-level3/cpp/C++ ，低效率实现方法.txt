### 解题思路
耗时较长。。。
执行用时 :24 ms, 在所有 C++ 提交中击败了 46.32%的用户
内存消耗 :7.9 MB, 在所有 C++ 提交中击败了100.00%的用户

先把string 转换为C字符串。
从第一个字符开始判断，若 为 '.'或者相等，判断第二个字符是否为'*', 
第二个字符若为* ，则 从*代表 0 个前一个字符（+2个字节，跳过）开始递归调用，
返回true的话说明匹配，不匹配的话，则*代表一个字符，s字符串指针+1,p指针不动；
最后两个字符串指针都移到字符串尾部，则说明匹配，返回true。
### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        const char *s_beg = s.c_str();
        const char * s_end = s_beg + s.size();
        const char *p_beg = p.c_str();
        const char * p_end = p_beg + p.size();
        return Is_Match(s_beg,s_end,p_beg, p_end); 
    }
    bool Is_Match(const char *s_beg , const char * const s_end, const char * p_beg , const char * const p_end)
    {
        while( s_beg < s_end && p_beg < p_end)
        {
            if( '.' == *p_beg || *s_beg == *p_beg)
            {
                if((p_beg+1)<p_end && '*' == *(p_beg+1))
                {    
                    if(Is_Match(s_beg,s_end,p_beg+2,p_end))
                        return true;
                    else ++s_beg;
                }
                else
                {
                    ++s_beg;
                    ++p_beg;
                }
            }
            else if((p_beg+1)<p_end && '*' == *(p_beg+1))
                p_beg += 2;
            else 
                return false;
        }
       while((p_beg+1) <p_end && '*' == *(p_beg +1))
            p_beg += 2;
        if(s_beg<s_end || p_beg < p_end )
            return false;
        else 
            return true;
    }
};
```