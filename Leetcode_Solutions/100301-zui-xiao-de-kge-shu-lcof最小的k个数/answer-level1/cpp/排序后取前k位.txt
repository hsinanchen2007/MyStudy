### 解题思路

sort函数对数组排序
取前k位返回

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;

        sort(arr.begin(),arr.begin()+arr.size());

        for(int i = 0;i<k;i++)
            res.push_back(arr[i]);

        return res;
    }
};
```