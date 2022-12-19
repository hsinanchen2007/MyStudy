![捕获.PNG](https://pic.leetcode-cn.com/11a9e5c497bea4ee042a8872e3308c74e13915506263d26931e25e87f2ac1ad0-%E6%8D%95%E8%8E%B7.PNG)
```
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        return vector<int>(arr.begin(),arr.begin()+k);
    }
};
```
