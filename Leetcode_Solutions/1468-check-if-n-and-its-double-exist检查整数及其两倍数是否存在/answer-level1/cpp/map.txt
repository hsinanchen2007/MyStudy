### 解题思路
注意特判0

### 代码

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i = 0 ; i < arr.size() ; ++i)
        {
            mp[arr[i]] += 1;
            if(arr[i] != 0 && (mp.count(arr[i] * 2) || (arr[i] % 2 == 0 && 
            mp.count(arr[i] / 2))))
                return true;
            if(arr[i] == 0 && mp[0] > 1)
                return true;
        }
        return false;
    }
};
```