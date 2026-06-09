### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> alphaMap(26, 0);
        for(int i = 0; i < S.size(); i++){
            alphaMap[S[i] - 'a']++;
        }
        vector<int> res;
        vector<char> tmp;
        for(int i = 0; i < S.size(); i++){
            tmp.push_back(S[i]);
            alphaMap[S[i] - 'a']--;
            int j = 0;
            for(; j < tmp.size(); j++){
                if(alphaMap[tmp[j] - 'a'] != 0){
                    break;
                }
            }
            if(j == tmp.size()){
                res.push_back(tmp.size());
                vector<char>().swap(tmp);
            }
        }
        return res;
    }
};
```