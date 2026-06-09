```
class Solution {
public:
    int change[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    char single[3] = {'0', '1', '8'};
    void dfs(int index, int n, string& prefix, string& suffix, int& ret, string small, string big){
        if(index == n / 2 + 1){
            string tmp = suffix;
            reverse(tmp.begin(), tmp.end());
            if(n % 2 == 0){
                string candidate = prefix + tmp;
                if(candidate >= small && candidate <= big) ret++;
            }else{
                string candidate = "";
                for(int i  = 0; i < 3; ++i){
                    candidate = prefix + single[i] + tmp;
                    if(candidate >= small && candidate <= big) ret++;
                }
            }
            return;
        }
        
        for(int i = 0;  i < 10; ++i){
            if(n > 1 && index == 1 && i == 0) continue;
            if(change[i] != -1){
                prefix += to_string(i);
                suffix += to_string(change[i]);
                dfs(index + 1, n, prefix, suffix, ret, small, big);
                prefix = prefix.substr(0, prefix.size() - 1);
                suffix = suffix.substr(0, suffix.size() - 1);
            }
        }
    }
    int strobogrammaticInRange(string low, string high) {
        int ans = 0;
        int lowsize = low.size();
        int highsize = high.size();
        int ret = 0;
        string prefix = "", suffix = "";
        if(lowsize == highsize){
            dfs(1, lowsize, prefix, suffix, ret, low, high);
            return ret;
        }
        
        for(int i = lowsize; i <= highsize; ++i){
            ret = 0, prefix = "", suffix = "";
            if(i == lowsize) dfs(1, i, prefix, suffix, ret, low, "999999999999999");
            else if(i == highsize) dfs(1, i, prefix, suffix, ret, "0", high);
            else dfs(1, i, prefix, suffix, ret, "0", "999999999999999"), cout<<ret<<endl;
            ans += ret;
        }
        return ans;
    }
};
```