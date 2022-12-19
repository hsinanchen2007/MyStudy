# 解答
dfs + 回溯。

图例：（字丑勿怪）

![在这里插入图片描述](https://pic.leetcode-cn.com/b61250ca0f4a19010dc64fe1523d40e323cdb75ffaa41f05c56a0b7a5f315a4d.png)

代码：
```cpp
class Solution {
public:
    bool isRight( string& s, int begin, int end){
        while( begin < end)
            if( s[begin] == s[end])
                begin++, end--;
            else
                return false;
        return true;
    }
    
    vector<vector<string>> result;
        
    void dfs( string& s, int begin, vector<string> temp){
        if( s.size() == begin){
            result.push_back( temp);
            return ;
        }
        
        for( int i = begin, len; i < s.size(); i += len + 1)
            for( len = 0; i + len < s.size(); len++){
                string now = s.substr( i, len + 1);
                if( isRight( now, 0, now.size() - 1)){
                    temp.push_back( now);
                    dfs( s, i + len + 1, temp);
                    temp.pop_back();
                }
            }
    }
    vector<vector<string>> partition(string s) {
        dfs( s, 0, {});
        return result;
    }
};
```
