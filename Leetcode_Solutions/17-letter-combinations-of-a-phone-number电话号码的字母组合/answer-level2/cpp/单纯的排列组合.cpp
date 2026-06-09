
```c++
class Solution {
public:  
    unordered_map<char, vector<string>> dict;  
    vector<string> letterCombinations(string digits) {
        
        //vector<char> v0 = {}, v1 = {};
        vector<string> v2={"a", "b", "c"};vector<string> v3={"d", "e", "f"};
        vector<string> v4={"g", "h", "i"};vector<string> v5={"j", "k", "l"};
        vector<string> v6={"m", "n", "o"};vector<string> v7={"p", "q", "r", "s"};
        vector<string> v8={"t", "u", "v"};vector<string> v9={"w", "x", "y", "z"};
        
        dict['2']=v2;dict['3']=v3;dict['4']=v4;dict['5']=v5;dict['6']=v6;dict['7']=v7;dict['8']=v8;dict['9']=v9;

        vector<char> input = {};
        vector<string> res = {};
        if(digits.size()==0) return res;
        //res = dict[digits[0]];
        for(int i=0; i<digits.size(); i++) input.push_back(digits[i]);
        for(int i=0; i<dict[digits[digits.size()-1]].size(); i++)
            res.push_back(dict[digits[digits.size()-1]][i]);
        if(digits.size()==1) return res;
        for(int i=digits.size()-2; i>=0; i--){
            vector<string> cur_v = dict[digits[i]];
            vector<string> tmp = {};
            for(int j=0; j<cur_v.size(); j++){
                for(int k=0; k<res.size(); k++){
                    tmp.push_back(cur_v[j]+res[k]);
                }
            }
            res = tmp;
        }
        return res; 
    }
};
```
