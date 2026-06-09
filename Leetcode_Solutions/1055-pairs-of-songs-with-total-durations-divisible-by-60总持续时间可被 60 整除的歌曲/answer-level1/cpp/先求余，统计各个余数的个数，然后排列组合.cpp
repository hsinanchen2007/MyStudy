```
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for(int i=0;i<time.size();i++){
            time[i]=time[i]%60;
        }
        int num[60]={0};
        for(int i=0;i<time.size();i++){
            num[time[i]]+=1;
        }
        int ans=0;
        ans=ans+num[0]*(num[0]-1)/2;
        ans=ans+num[30]*(num[30]-1)/2;
        for(int i=1;i<30;i++){
            ans=ans+num[i]*num[60-i];
        }
        return ans;


    }
};
```
