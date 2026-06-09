```
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double minn = INT_MAX, maxn = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            minn = min(minn, (double)nums[i]);
            maxn = max(maxn, (double)nums[i]);
        }
        while((maxn - minn) > 0.000001){
            double mid = (minn + maxn)/2;
            if(check(nums, k, mid))
                minn = mid;
            else
                maxn = mid;
        }
        return minn;
    }
    
    bool check(vector<int>& nums, int k , double mid){
        vector<double> delta(nums.size());
        delta[0] = nums[0] - mid;
        for(int i = 1; i < nums.size(); ++i){
            delta[i] = nums[i] - mid + delta[i - 1];
        }
        double min_sum = 0, sum = delta[k - 1];
        for(int i = k; i < delta.size(); ++i){
            if((sum - min_sum) >= 0) return true;
            min_sum = min(min_sum, delta[i - k]);
            sum = delta[i];
        }
        if((sum - min_sum) >= 0) return true;
        return false;
    }
};
```
