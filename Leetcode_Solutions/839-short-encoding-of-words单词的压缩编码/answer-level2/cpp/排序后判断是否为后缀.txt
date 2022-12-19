

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &s : words){
            reverse(s.begin(),s.end());
        }
        sort(words.begin(),words.end());
        int res=0;
        for(int i=0;i<words.size()-1;i++){
            int size=words[i].size();
            if(words[i]==words[i+1].substr(0,size)) continue;
            res+=size+1;
        }
        return res+words.back().size()+1;
    }
};
```