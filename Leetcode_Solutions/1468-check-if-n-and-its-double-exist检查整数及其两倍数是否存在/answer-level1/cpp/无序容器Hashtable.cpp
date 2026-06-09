### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }

        for(int i = 0; i < arr.size(); i++) {
            auto s = mp.find(arr[i] * 2);
            if(s != mp.end() && s->second != i) {
                return true;
            }
        }

        return false;
    }
};
```