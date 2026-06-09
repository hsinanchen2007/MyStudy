```
class Solution {
public:
    int change[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    void dfs(int index, int n, string& prefix, string& suffix){
        if(index == n / 2 + 1){
            string tmp = suffix;
            reverse(tmp.begin(), tmp.end());
            if(n % 2 == 0){
                ret.push_back(prefix + tmp);
            }else{
                ret.push_back(prefix + '0' + tmp);
                ret.push_back(prefix + '1' + tmp);
                ret.push_back(prefix + '8' + tmp);
            }
            return;
        }
        
        for(int i = 0;  i < 10; ++i){
            if(n > 1 && index == 1 && i == 0) continue;
            if(change[i] != -1){
                prefix += to_string(i);
                suffix += to_string(change[i]);
                dfs(index + 1, n, prefix, suffix);
                prefix = prefix.substr(0, prefix.size() - 1);
                suffix = suffix.substr(0, suffix.size() - 1);
            }
        }
    }
    vector<string> findStrobogrammatic(int n) {
        int index = 1;
        string prefix = "", suffix = "";
        dfs(index, n, prefix, suffix);
        return ret;
    }
private:
    vector<string> ret;
};
```