T4: 口算难题
典型的回溯算法。 理论上时间复杂度为$O(10! * k)$, 其中$k$ 为每次计算的常数因子， 约等于$\Sigma |words_i| + |result|$. 注意两点。 
1. 首位不能为0
2. 找到结果后立刻退出回溯
3. (Optional) 注意回溯顺序。 

代码贴上， 2800ms险过（虽然12点多才交）。
```
class Solution {
public:
    
    int isFirst[26], value[26];
    int letters[26], used[26];
    
    int vis[10];
    
    int wordsToValue(string &words){
        int len = words.length();
        
        int ans = 0;
        for(int i = 0; i < len; i++){
            int cid = words[i] - 'A';
            
            ans = ans * 10 + value[cid];
        }
        
        return ans;
    }
    
    void run(int i, vector<string>& words, string &result, int &ok){
        if(i > letters[0]){
            int sum = 0;
            for(int i = 0; i < words.size(); i++){
                int cur = 0;
                sum += wordsToValue(words[i]);
            }
            
            
            
            int cons = wordsToValue(result);
            
            if(sum == cons) ok = 1;
            
            //printf("%d %d\n",sum, cons);
            
            return;
        }
        
        if(ok)return;
        
        else{
            int cid = letters[i];
            for(int j = 0; j < 10; j++){
                
                if(!vis[j]){
                    if(!isFirst[cid] || (j > 0 && isFirst[cid])){
                        value[cid] = j;
                        vis[j] = 1;
                        run(i+1, words, result, ok);
                        if(ok) break;
                        vis[j] = 0;
                    }
                }
            }
        }
        
        
    }
    
    bool isSolvable(vector<string>& words, string result) {
        int n = words.size();
        int ok = 0;
        
        for(int i = 0; i < n; i++){
            int len = words[i].length();
            for(int j = 0; j < len; j++){
                int cid = words[i][j] - 'A';
                
                if(j == 0){
                    isFirst[cid] = 1;
                }
                
                if(!used[cid]){
                    letters[++letters[0]] = cid;
                    used[cid] = 1;
                }
            }
        }
        
        int len = result.length();
        for(int j = 0; j < len; j++){
                int cid = result[j] - 'A';
                
                if(j == 0){
                    isFirst[cid] = 1;
                }
                
                if(!used[cid]){
                    letters[++letters[0]] = cid;
                    used[cid] = 1;
                }
            }
        
        printf("%d\n", letters[0]);
        
        run(1, words, result, ok);
        
        return ok == 1;
    }
};
```

感谢各位批评指正。 如果有更优的算法欢迎讨论。