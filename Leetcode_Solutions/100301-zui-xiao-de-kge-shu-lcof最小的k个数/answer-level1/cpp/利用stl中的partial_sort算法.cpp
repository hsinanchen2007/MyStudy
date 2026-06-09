### 解题思路
利用stl中的partial_sort算法

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.empty()||k<=0)return vector<int>();
        vector<int> res(k);
        partial_sort_copy(arr.begin(), arr.end(), res.begin(), res.end());
        return res;
    }
};
```

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.empty()||k<=0)return vector<int>();
        partial_sort(arr.begin(), arr.begin()+k, arr.end());
        vector<int> res(arr.begin(),arr.begin()+k);
        return res;
    }
};