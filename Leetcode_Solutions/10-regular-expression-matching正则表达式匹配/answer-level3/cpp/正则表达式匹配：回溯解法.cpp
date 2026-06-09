假设不需要考虑 '*', 那么问题很容易解决，因此这里我们也主要看星号的匹配。

我们使用回溯来解决问题。

对于 '*' 而言，它可以使前一个字母重复无数次，即 0,1,2,3,4,.....次数，关键在于，需要重复几次才能使两个字符串匹配。

假设当前位于字符串 p 的第 i 个字符，字符串 s 的第 j 个字符，且 p[i+1] == * 成立。

若 s[j] != p[i], 那么 * 应当重复 0 次。

若 s[j] == p[i], 则应当考虑 p 和 s 之后的字符。

例如：
![在这里插入图片描述](https://pic.leetcode-cn.com/07a002832d41b7d43a9455cd9130affe1c05fb26fc1221bb04d38e9b4efc2995.png)

我们的策略是：检测到最长的相同的字符个数，例如上例 3> 中，最长的重复次数为 3, 然后从最长重复次数开始向 0 递减，依次检测在之前情况下可否满足字符串相同。

代码：
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        match( s, p, 0, 0);
        return flag;
    }
    
    int flag = 0;
    void match( string& s, string& p, int begin_s, int begin_p){
        if( (begin_s > s.size() && begin_p < p.size())
       || (begin_s < s.size() && begin_p > p.size()) )
            return ;
    
        // i 表示 p 的当前位置；j 表示 s 的当前位置
        int j = begin_s, i = begin_p;
        
        for( ; i < p.size() ; i++){
            if( i + 1 < p.size() && p[i + 1] == '*'){
                //计算 s 中与 p[i] 相等的长度
                int the_same_Pi = 0;
                for( int k = j; k < s.size(); k++)
                    if( s[k] == p[i] || p[i] == '.')
                        the_same_Pi++;
                    else
                        break;
                
                while( the_same_Pi >= 0){
                    match( s, p, begin_s + the_same_Pi, begin_p + 2);
                    the_same_Pi--;
                }

            }
            else{
                if( p[i] == s[j] || p[i] == '.')
                    match( s, p, begin_s + 1, i + 1);
                break;
            }
        }
        
        if( j == s.size() && i == p.size())
            flag = 1;
        return ;
    }
};
```