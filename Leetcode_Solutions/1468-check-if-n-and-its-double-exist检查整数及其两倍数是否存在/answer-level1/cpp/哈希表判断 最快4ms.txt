### 解题思路
简单易懂

### 代码

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr)
    {
        unordered_map<int, bool> mymap;
        int len = arr.size();
        for (int i = 0; i < len; i++)
        {
            if (mymap.count(arr[i]) > 0) return 1;
            if (arr[i] % 2 == 0) mymap[arr[i] / 2] = 1;
            mymap[arr[i] * 2] = 1;
        }
        return 0;
    }
};
```