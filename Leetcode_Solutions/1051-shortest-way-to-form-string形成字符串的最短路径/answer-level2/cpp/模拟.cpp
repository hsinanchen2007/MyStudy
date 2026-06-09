```
class Solution {
public:
    int shortestWay(string source, string target) {
        if(source == target) return 1;
        if(target.size() == 0) return 0;
        vector<bool> vis(30, false);
        for(auto c : source) vis[c - 'a'] = true;
        for(auto c : target) if(vis[c - 'a'] == false) return -1;
        int ret = 0;
        int i  = 0, j = 0;
        while(i < target.size()){
            j = 0;
            while(j < source.size() && i < target.size()){
                if(source[j] != target[i]) j++;
                else j++, i++;
            }
            if(j == source.size() || i == target.size()) ret++;
        }
        
        return ret;
    }
};
```