### 解题思路
直接使用sort，取前k个即可

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> re;
        for (int i=0; i<k; i++){
            re.push_back(arr[i]);
        }
        return re;
    }
};
```