在strs为空的时候，直接返回""；
如果strs不为空，就用第一个字符串的长度为外循环，strs.size()为内循环；
检验前缀字母，不同就用flag = false ；
用以检验res 是否需要增加
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int l = strs.size();
        
        bool flag = true;
        string res = "";
        if(l == 0)
            return res;
        int l2 = strs[0].length();
        for( int i = 0 ; i < l2; i ++) {
                for( int j = 1 ; j < l ; j++){
                    if(strs[j][i] != strs[0][i])
                        {
                            flag = false;
                            break;
                        }
                }
                if(flag )
                    res+=strs[0][i];
                else
                    i = l2 ;
        }
        return res;
    }
};