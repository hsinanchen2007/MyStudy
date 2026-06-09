```
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int left = target / n;
        sort(arr.begin(), arr.end());
        int right = arr[n - 1];
        while(left < right){
            int mid = (left + right) / 2;
            if(getABS(arr, target, mid) > getABS(arr, target, mid + 1)){
                left = mid + 1; 
            }
            else{
                right = mid;
            }
        }
        return left;
    }
    int getABS(vector<int>& arr, int target, int value){
        int n = arr.size();
        int cnt = 0, sum = 0;
        for(auto a:arr){
            if(a < value)
                sum += a;
            else{
                sum += value * (n - cnt);
                break;
            } 
            cnt ++;
        }
        return abs(sum - target);
    }
};
```
