```
class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        
        int n=calories.size();

        int res=0;

        int sum=0;
        sum = accumulate(calories.begin(),calories.begin()+k,0);
        if(sum<lower)--res;
        else if(sum>upper)++res;

        for(int i=k;i<n;++i)
        {
            sum+=(calories[i]-calories[i-k]);
            if(sum<lower)--res;
            else if(sum>upper)++res;
        }

        return res;
    }
};
```
