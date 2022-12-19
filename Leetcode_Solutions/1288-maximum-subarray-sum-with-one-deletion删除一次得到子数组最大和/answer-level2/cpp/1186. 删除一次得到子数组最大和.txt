```
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> f(n);
        vector<int> g(n);
        f[0] = arr[0];
        g[0] = INT_MIN/2;
        for(int i=1;i<n;i++){
            f[i] = max(f[i-1]+arr[i],arr[i]);
            g[i] = max(g[i-1]+arr[i],f[i-1]);
        }
        int res = INT_MIN/2; 
        for(int i=0;i<n;i++){
            res = max(res,max(f[i],g[i]));
        }
        return res;
    }
};
```
