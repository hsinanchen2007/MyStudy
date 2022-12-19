```
class Solution {
public:
    
    bool p[11];
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int res = 0;        

        sort(reservedSeats.begin(), reservedSeats.end());
        
        int ans = 0;
        for(int i = 0, j = 0; i < reservedSeats.size(); i = j){
            while(j < reservedSeats.size() && reservedSeats[i][0] == reservedSeats[j][0]) ++j;
            ans ++;
            
            for(int k = i; k < j; ++k){
                p[reservedSeats[k][1]] = 1;
            }
            
            for(int k = 2; k <= 6; ++k){
                if(p[k] == 1 || (k != 2 && k != 4 && k != 6)) continue;
                
                 bool flag = true;
               for(int l = 0; l < 4; ++l){
                   if(p[k + l] == 1) {flag = false; break;}
                   p[k + l] = 1;
                   
               }
                if(flag) res ++;
                
            }
            
            memset(p, 0, 11);
            
        }
        
        res += (n - ans) * 2;
        
        return res;
        
    }
};
```
