### 解题思路
直接从小到大排序，并输出前k个值。
学习官方的第一种解法，还有几种其他解法，推荐去看一下。

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ret(k,0);
        sort(arr.begin(),arr.end());
        for(int i = 0; i < k; i++)
            ret[i] = arr[i];
        return ret;
    }
};
```