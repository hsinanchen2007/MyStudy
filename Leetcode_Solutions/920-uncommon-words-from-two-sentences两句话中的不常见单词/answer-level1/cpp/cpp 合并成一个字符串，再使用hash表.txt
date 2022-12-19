### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        string str = A+" "+B;
        int start = 0;
        vector<string> res;
        for(int i = 0;i<str.size();i++){
            if(str[i] == ' '){
                string temp = str.substr(start,i-start);
                res.push_back(temp);
                start = i+1;
            }
        }
        string temp = str.substr(start,str.size()-start);
        res.push_back(temp);
        unordered_map<string,int> hash;

        for(int i = 0;i<res.size();i++){
           hash[res[i]]++;
        }
        vector<string> resA;
        for(auto it = hash.begin();it != hash.end();it++){
            if(it->second == 1){
                resA.push_back(it->first);
            }
        }
        return resA;
    }
};
```