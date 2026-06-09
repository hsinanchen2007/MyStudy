### 解题思路
直接看代码，很简单。

### 代码

```cpp
class Solution {
public:
    string customSortString(string S, string T) {
        map<char, int> hash;
        for(const char &c: T) hash[c]++;
        string ans;
        for(const char &sc: S){
            for(int i = 0; i < hash[sc]; i++){
                ans.push_back(sc);
            }
            hash[sc] = 0;
        }
        for(auto it = hash.begin(); it != hash.end(); it++){
            if(it->second > 0){
                for(int i = 0; i < it->second; i++){
                    ans.push_back(it->first);
                }
            }
        }
        return ans;
    }
};
```