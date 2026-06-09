### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> sv ;
    map<int,vector<char>> m ;

//--------------------------------------------------- Recursive  Revision --------------------------------------------------------------------
    void _helper(string & digits , int index ,string cur_str){
        if ( index == digits.size() ) {
            sv.push_back(cur_str);
            return ;
        }
        for( auto ch : m[digits[index]-'0']  ){
            _helper(digits,index+1,cur_str+ch);
        }
    }

    vector<string> _letterCombinations(string digits) {
        if(digits.size()==0)return sv;
        char alpha='a';
        for( int i = 2 ; i <= 9 ; ++i ){
            int alpha_nums = ( i == 7 || i == 9 ) ? 4 : 3 ;
            for( int j = 0 ; j < alpha_nums ; ++j ){ m[i].push_back(alpha++);}
        }
        _helper(digits,0,"");
        return sv;
    }

//--------------------------------------------------- None Recursive Revision -------------------------------------------------------------------

    void helper(string & digits){
        int depth = digits.size();
        vector<int> idx_stack(depth,0) ;
        vector<char> str_stack ;
        bool loops_done =false ; 
        while(!loops_done){
            if ( str_stack.size() < depth ){
                int pos = str_stack.size();
                if ( idx_stack[pos] == m[digits[pos]-'0'].size() ) {
                    idx_stack[pos]=0;
                    if( pos == 0 )  loops_done = true ;
                    else  str_stack.pop_back();
                    
               }else{
                    str_stack.push_back(m[digits[pos]-'0'][idx_stack[pos]++]);
               }
            }else{
                sv.push_back(string(str_stack.begin(),str_stack.end()));
                str_stack.pop_back();
            }
        }

    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return sv;
        char alpha='a';
        for( int i = 2 ; i <= 9 ; ++i ){
            int alpha_nums = ( i == 7 || i == 9 ) ? 4 : 3 ;
            for( int j = 0 ; j < alpha_nums ; ++j ){ m[i].push_back(alpha++);}
        }
        helper(digits);
        return sv;
    }
};
```