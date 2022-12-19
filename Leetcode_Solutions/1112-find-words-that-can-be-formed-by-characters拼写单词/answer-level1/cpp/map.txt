### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res=0;
        int flag=1;
        map<char,int> map1;
        vector<map<char,int>> p(words.size());
        for(int i=0;i<chars.size();i++){
            map1[chars[i]]++;
        }
        for(int i=0;i<words.size();i++){
            flag=1;
            for(int j=0;j<words[i].size();j++){
                p[i][words[i][j]]++;
            }
            for(auto it=p[i].begin();it!=p[i].end();it++){
                if(it->second > map1[it->first]){
                    flag=0;
                    break;
                }
            }
            if(flag==1) res+=words[i].size();
        }

        return res;

    }
};
```