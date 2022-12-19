### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for(int i = 0;i<paragraph.size();i++){
            if(isalpha(paragraph[i]))
                paragraph[i] = tolower(paragraph[i]);
            else
                paragraph[i] = ' ';
        }
        unordered_map<string,int> hash;
        string word;
        stringstream ss(paragraph);
        while(ss>>word){
            hash[word]++;
        }
        for(string s : banned){
            hash[s] = 0;
        }
        int maxW = 0;
        string res;
        for(auto iter : hash){
            if(iter.second > maxW){
                maxW=iter.second;
                res = iter.first;
            }
        }
        return res;
    }
};
```