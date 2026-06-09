```
class Solution {
public:
     map<char,string> mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> res;
    void DFS(string cur,string next_digits){
        if(next_digits.size()==0)
            res.push_back(cur);
        else{
            char digit=next_digits[0];//获取当前处理的数字
            string letters=mp[digit];//从map中获取当前处理的数字对应的字符串
            for(int i=0;i<letters.size();i++){
                string letter=letters.substr(i,1);//待添加到尾部的字符串
                DFS(cur+letter,next_digits.substr(1));//从第2个字符开始，截取next_digits
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
        else
            DFS("",digits);
        return res;
    }
};
```
