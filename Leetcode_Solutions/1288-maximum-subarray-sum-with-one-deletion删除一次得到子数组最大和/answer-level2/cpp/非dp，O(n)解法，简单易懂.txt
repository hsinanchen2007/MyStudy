不多说，show you my code
```
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if(n<=1)return arr[0];
        vector<int>presum(n,0),lastsum(n,0);
        int sum = 0,re = INT_MIN;
        for(int i=0;i<n;i++){
            sum += arr[i];
            re = max(sum,re);
            presum[i] = sum;
            if(sum < 0)sum = 0;
        }
        sum = 0;
        for(int i=n-1;i>=0;i--){
            sum += arr[i];
            re = max(sum,re);
            lastsum[i] = sum;
            if(sum < 0)sum = 0;
        }
        for(int i=1;i<n-1;i++){
            if(arr[i] < 0){
                re = max(re,presum[i-1]+lastsum[i+1]);
            }
        }
        return re;
    }
};
```
