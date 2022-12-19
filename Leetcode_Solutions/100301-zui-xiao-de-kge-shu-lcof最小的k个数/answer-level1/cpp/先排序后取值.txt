### 解题思路
最小的k个数，也就是排序后的前k的数。
所以先排序，然后取出前k个值。
### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> a(arr.begin(),arr.begin()+k);
        return a;

    }
};
```