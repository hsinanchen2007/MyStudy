### 解题思路
  因为是简单题就直接用sort了。当然了，想锻炼能力肯定是要多想想的，多思考几种解决方案更好！

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin() , arr.end());
        vector<int> r;
        for(int i = 0 ; i < k ; i++){
            r.push_back(arr[i]);
        }
        return r;
    }
};
```