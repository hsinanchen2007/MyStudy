大家可以去参考国际版的leetcode.

1. 暴力破解
```
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int res = 0;
        vector<int> sum(n+1,0);
        
        for(int i = 0;i < n; ++i){
            sum[i+1] = sum[i] + (hours[i] > 8?1:(-1));
            for(int j = 0;j <= i; ++j){
                if(sum[i+1] - sum[j] > 0){
                    res = max(res,i+1-j);
                    break;
                }
            }
        }
        return res;
    }
};
```

2. 二分查找
```
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int res = 0;
        vector<int> sum(n+1,0);
        vector<int> prefix(n+1,0);
        
        for(int i = 0;i < n; ++i){
            sum[i+1] = sum[i] + (hours[i] > 8?1:(-1));
        }
        /*intial*/
        int mx = 0;
        for(int i = 1; i <= n; ++i){
            mx = min(sum[i],mx);
            prefix[i] = mx;
        }
        
        for(int i = 1;i <= n; ++i){
           int l = 0;
           int r = i-1;
           while(l <= r){
               int mid = l+(r-l)/2;
               if(prefix[mid] >= sum[i]){
                   l = mid + 1;
               }else{
                   r = mid - 1;
               }
           }
           res = max(res,i-(r+1));
        }
        
        return res;
    }
};
```
3. 最快解法
```
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int res = 0;
        vector<int> sum(n+1,0);
        unordered_map<int,int> seen;
        
        for(int i = 0;i < n; ++i){
            sum[i+1] = sum[i] + (hours[i] > 8?1:(-1));
            if(sum[i+1] > 0){
                res = max(res,i+1);
            }else{
                if(seen.count(sum[i+1]-1)){
                    res = max(res,i-seen[sum[i+1]-1]);
                }
            }
            
            if(!seen.count(sum[i+1])){
                seen[sum[i+1]] = i;
            }
        }        
        
        return res;
    }
};
```