
### 代码

```cpp
class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        if(num.empty()||words.empty()) return {};

        vector<string> ans;
        map<char,string> help={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},
        {'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        
        for(string word:words)
        {
            bool is=true;
            for(int i=0;i<word.size();i++)
            {
                if(help[num[i]].find(word[i])==-1)
                {
                    is=false;
                    break;
                }
            }
            if(is) ans.push_back(word);
        }

        return ans;
    }
};
```