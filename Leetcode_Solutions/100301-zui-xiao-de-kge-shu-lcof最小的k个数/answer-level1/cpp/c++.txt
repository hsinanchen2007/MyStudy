### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> res;
        if(k==0) return res;
        res.insert(res.begin(),arr.begin(),arr.begin()+k);
        return res;


    }
};
```