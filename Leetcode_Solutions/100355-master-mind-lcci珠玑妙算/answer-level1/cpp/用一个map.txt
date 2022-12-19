```
class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        vector<int> ans(2,0);
        for(int i=0;i<4;++i){
            if(solution[i]==guess[i]){
                ++ans[0];
                solution[i]=' ';
                guess[i]=' ';
            }
        }
        map<char,int> m;
        for(auto a:solution){
            if(a!=' '){
                ++m[a];
            }
        }
        for(auto a:guess){
            if(m.count(a)){
                if(m[a]>0){
                    ++ans[1];
                    --m[a];
                }
            }
        }
        return ans;
    }
};
```
