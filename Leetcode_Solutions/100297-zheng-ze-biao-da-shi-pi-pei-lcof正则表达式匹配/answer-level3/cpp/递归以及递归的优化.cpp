### 解题思路
通过分析，应该可以想到用递归办法进行处理。可是提交代码时，提示耗时太多。那么就只能作进一步分析，考虑到递归虽然代码简单，但是有可能存在重复计算的问题，这点在《剑指offer》书中有讲，通过加打印信息确实发现了重复调用。那么，就只能想办法规避这些重复计算，能想到的就是把中间计算的结果存下来，于是就采用1个二维数组存放子问题的计算结果。说实话，直到做完这道题我依然不太赞同这是一道动态规划的题目，因为它除了满足“存在多个重复的子问题”外，并不存在最优解以及从上往下分析从下往上解决问题的特点，充其量算是递归的一种优化。
这里面尤其要注意几个测例：
s = “aa”, p = "a*"
s = "a", p = "ab*" 
s = "a", p = "aa*"
期间二维矩阵创建时为何要+1，以及对于二者序号是否越界在何处进行判断通过上述几个例子将深有体会（别问我为什么知道，一步一步踩过来的）
![20200325210006.png](https://pic.leetcode-cn.com/2f6f4bce8d4ed9041fd6063650cc78ccd4be9d1f4a486b8847bd87b5d5778769-20200325210006.png)

### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        m_vecRecord = vector<vector<int>>( s.size() + 1, vector<int>( p.size() + 1, -1 ) );
        return match( s, 0, p, 0 );
    }

private:
    bool match(const string &s, const int &nSIndex, const string &p, const int &nPIndex)
    {  
        if( nPIndex >= p.size() )
        {
            return ( nSIndex >= s.size() );
        }
        
        if( -1 != m_vecRecord.at( nSIndex ).at( nPIndex ) )
        {
            return m_vecRecord.at( nSIndex ).at( nPIndex );
        }

        bool bRes = false; //默认不匹配

        //当前待匹配字符的下一个字符是*
        if( ( ( nPIndex + 1 ) < p.size() ) && ( p.at( nPIndex + 1 ) == '*' ) ) 
        {    
            //'*'前一字符出现0次
            bRes |= match( s, nSIndex, p, nPIndex + 2 ); 

            if( ( nSIndex < s.size() ) && ( s.at( nSIndex ) == p.at( nPIndex ) || p.at( nPIndex ) == '.' ) ) 
            {
                bRes |= match( s, nSIndex + 1, p, nPIndex ); //'*'前一字符出现1次以上
                bRes |= match( s, nSIndex + 1, p, nPIndex + 2 ); //'*'前一字符出现1次
            }
        }

        else
        {
            if( ( nSIndex < s.size() ) && ( s.at( nSIndex ) == p.at( nPIndex ) || p.at( nPIndex ) == '.' ) )
            {
                bRes |= match( s, nSIndex + 1, p, nPIndex + 1 );
            }
        }

        m_vecRecord.at( nSIndex ).at( nPIndex ) = bRes;
        return bRes;
    }

private:
    vector<vector<int>> m_vecRecord;
};
```