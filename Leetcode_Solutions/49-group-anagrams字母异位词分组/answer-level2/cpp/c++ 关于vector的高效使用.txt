
在此声明，以下的代码是参考了评论区的大神的，非常感谢这位大神！让我对vector的理解和运用更上一层楼！
```
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        if(strs.size() == 0){
            return output;
        }
        unordered_map<string, vector<string>>dic;
        for (auto str:strs){
            string t = str;
            sort(t.begin(),t.end());
            dic[t].push_back(str);
        }
        for(auto &pair:dic){
            output.push_back(move(pair.second));
        }
        
        return output;
    }
};
```

小白收益：
1. 关于string也可以按照字母排序
2. move的使用