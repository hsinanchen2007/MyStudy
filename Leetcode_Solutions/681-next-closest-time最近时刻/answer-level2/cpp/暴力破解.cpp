```
class Solution {
public:
    string parseTo(int h1,int h2,int m1,int m2){
        string ans = "00:00";
        ans[0] = h1 + '0';
        ans[1] = h2 + '0';
        ans[3] = m1 + '0';
        ans[4] = m2 + '0';
        
        return ans;
    }
    
    string nextClosestTime(string time) {
        int h1 = time[0] - '0';
        int h2 = time[1] - '0';
        int m1 = time[3] - '0';
        int m2 = time[4] - '0';
        int now = (h1*10 + h2)*60 + m1*10 + m2;
        
        int t[4] = {h1,h2,m1,m2}; 
        vector<int> res;
        /*first test*/
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                for(int m = 0; m < 4; ++m){
                    for(int n = 0; n < 4; ++n){
                        if((t[i] < 2 || (t[i] == 2 && t[j] <= 4))&&(t[m] <= 5)){
                            res.push_back((t[i]*10 + t[j])*60 + t[m]*10 + t[n]);
                        }
                    }
                }
            }
        }    
        
        sort(res.begin(),res.end());
        auto it = upper_bound(res.begin(),res.end(),now);
        if(it == res.end()){
            it = res.begin();
        }
        
        return parseTo((*it/60)/10,(*it/60)%10,(*it%60)/10,(*it%60)%10); 
    }
};
```
