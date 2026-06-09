

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        sort(arr.begin(),arr.end());       
        return vector<int>  (arr.begin(),arr.begin()+k);        //  range arr[_First, _Last);

    }
};
```