### 解题思路
很一般，空间没做到最优

### 代码

```cpp
class Solution {
public:
    vector<string> sv ;
    map<int,vector<char>> m ;

    void helper(string & digits , int index ,string cur_str){
        if ( index == digits.size() ) {
            sv.push_back(cur_str);
            return ;
        }
        for( auto ch : m[digits[index]-'0']  ){
            helper(digits,index+1,cur_str+ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return sv;
        char alpha='a';
        for( int i = 2 ; i <= 9 ; ++i ){
            int alpha_nums = ( i == 7 || i == 9 ) ? 4 : 3 ;
            for( int j = 0 ; j < alpha_nums ; ++j ){ m[i].push_back(alpha++);}
        }
        helper(digits,0,"");
        return sv;
    }
};
```