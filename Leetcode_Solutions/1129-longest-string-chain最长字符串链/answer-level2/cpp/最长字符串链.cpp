```
    bool judge(const string &prefix, const string &target){
        vector<int> count(26,0);
        for(auto val : target) count[val-'a']++;
        for(auto val : prefix){
            count[val-'a']--;
            if(count[val-'a']<0) return false;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        if(words.size()<=0) return 0;
        
        unordered_map<int, map<string,int>> intMap;
        int min_len = 0x7fffffff;
        int max_len = 0;
        for(auto val : words){
            intMap[val.length()][val] = 1;
            min_len = min(min_len, int(val.length()));
            max_len = max(max_len, int(val.length()));
        }
        int ans = 1;
        for(int i=min_len+1; i<=max_len; i++){
            if(intMap.find(i)==intMap.end()) continue;
            for(auto ite=intMap[i].begin(); ite!=intMap[i].end(); ite++){
                ite->second = 1;
                if(intMap.find(i-1)!=intMap.end()){
                    for(auto ite1=intMap[i-1].begin(); ite1!=intMap[i-1].end(); ite1++){
                        // judge whether ite1 is prefix of ite->first
                        if(judge(ite1->first, ite->first)){
                            ite->second = max(ite->second, 1+ite1->second);
                        }
                    }
                }
                ans = max(ans, ite->second);
            }
        }
        return ans;
    }
```