### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
         sort(arr.begin(),arr.end());
         vector<int>a;
         for(int i = 0; i < k;i++){
             a.push_back(arr[i]);
         }
        return a;
    }
};
```