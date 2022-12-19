### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:

    void splitString(string str,map<string,int> &strMap){
        int len = 0;
        for(int i = 0; i < str.length(); i++){
            char ch = str[i];
            if(ch == ' '){
                if(len != 0){
                    string subString = str.substr(i - len,len);
                    map<string,int>::iterator it = strMap.find(subString);
                    if(it != strMap.end()){
                        it->second = it->second + 1;
                    } else {
                        strMap.insert(pair<string, int>(subString,1));
                    }
                    len = 0;
                }
            } else{
                ++len;
            }
        }

        if(len > 0){
            string subString = str.substr( str.length()  - len,len);
            map<string,int>::iterator it = strMap.find(subString);
            if(it != strMap.end()){
                it->second = it->second + 1;
            } else {
                strMap.insert(pair<string, int>(subString,1));
            }
        }
    }
    vector<string> uncommonFromSentences(string A, string B) {
        map<string,int> countMap;
        splitString(A, countMap);
        splitString(B, countMap);
        vector<string> verStr;
        map<string, int>::iterator iter;
        for (iter=countMap.begin(); iter!=countMap.end(); iter++){
            if(iter->second == 1){
                // string rel = iter->first;
                verStr.push_back(iter->first);
            }
        }

        return verStr;

        


    }
};
```