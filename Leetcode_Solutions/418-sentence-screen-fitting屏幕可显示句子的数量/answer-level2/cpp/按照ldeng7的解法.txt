
```
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        int ans = 0;
        int curr = 0;
        int idx = 0;
        int l = 0;
        
        for(auto s : sentence){
            l += s.size() + 1;
        }
        
        for(int i = 0;i < rows; ++i){
            curr = cols;
            while(curr > 0 && curr >= sentence[idx].size() ){
                curr = curr - sentence[idx].size();
                                
                idx++;
                if(curr > 0){
                    curr--;
                }
                
                if(idx == n){
                    ans += curr/l + 1;
                    curr = curr%l; 
                    idx = 0;
                }
            }
        }
        
        return ans;
    }
};
```