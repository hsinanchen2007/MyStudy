### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> wd,ch;
        unordered_map<char,int>::iterator it;
        int cnt=0;
        for(int i=0;i<chars.length();i++)
        ch[chars[i]]++;
        for(int i=0;i<words.size();i++){
            wd.clear();
            for(int j=0;j<words[i].length();j++)
            wd[words[i][j]]++;
            int flag=1;
            for(it=wd.begin();it!=wd.end();it++){
                if(it->second>ch[it->first]){
                    flag=0;
                    break;
                }
            }
            if(flag)cnt+=words[i].size();
        }
        return cnt;
    }
};
```