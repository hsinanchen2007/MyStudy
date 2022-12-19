计算两个方向的最大子数组和，最后通过比较选择相加左右子数组和后最大的值。
```c++ []
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<int> ls(arr.size(), 0); // 从左到右的最大累加
        vector<int> rs(arr.size(), 0); // 从右到左

        int cur = 0; // 保存累加和
        for (int i = 0; i < arr.size(); i++) {
           if (cur < 0) { // 如果之前的累加和是负的，那么没必要还加之前的数了，直接从现在这个数开始
               ls[i] = arr[i];
               cur = arr[i];
           } else {
               cur += arr[i];
               ls[i] = cur;
           }
        }
        cur = 0;
        for (int i = arr.size()-1; i >= 0; i--) {
            if (cur < 0) {
               rs[i] = arr[i];
               cur = arr[i];
           } else {
               cur += arr[i];
               rs[i] = cur;
           } 
        }

        int res = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            if (i+2 < rs.size()) res = max(res, ls[i]+ rs[i+2]); // 不取中间数的子数组和
            if (i+1 < rs.size()) res = max(res, ls[i]+rs[i+1]);
            res = max(res, ls[i]);
            res = max(res, rs[i]);
        }
        return res;
    }
};
```

