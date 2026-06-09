### 解题思路
先排序，再循环输出

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> result;
        sort(arr.begin(),arr.end());
        for(int i=0;i<k;i++)
           result.push_back(arr[i]);
        return result;
    }
};
```