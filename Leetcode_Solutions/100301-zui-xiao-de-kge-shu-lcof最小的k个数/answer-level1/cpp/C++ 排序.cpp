### 解题思路
此处撰写解题思路
直接对数组从小到大排序取前k个数即可。

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        vector<int> result;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < k; i++)
        {
            result.push_back(arr[i]);
        }
        return result;
    }
};
```