```
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0, v = k * threshold;
        //子数组平均值 >= 阈值，也就是子数组和 >= 阈值 * 子数组长度
        int s = accumulate(arr.begin(), arr.begin() + k, 0);
        if (s >= v) ans++;
        for (int i = 0; i < arr.size() - k; i++) {
            s = s - arr[i] + arr[i + k];
            if (s >= v) ans++;
        }
        return ans;
    }
};
```
