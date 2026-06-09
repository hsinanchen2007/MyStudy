```
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        int absValue = arr[len - 1] - arr[0];
        for(int i = 0; i < len - 1; i++){
            absValue = min(absValue, arr[i + 1] - arr[i]);
        }
        vector<int>temp;
        vector<vector<int>>res;
        for(int i = 1; i < len; i++){
            if(absValue == (arr[i] - arr[i-1])){
                temp.push_back(arr[i - 1]);
                temp.push_back(arr[i]);
                res.push_back(temp);
            }
            temp.clear();
        }
        return res;
    }
};
```
![微信截图_20191206195600.png](https://pic.leetcode-cn.com/a6033449b8c5806abffc9c39a224d8c51b1acdd6d4d0f82543094cf32a8ccd95-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191206195600.png)
