### 解题思路
用map统计每个数字出现的次数，然后排序出现的次数，从大到小减，减到一半数组的一半后，返回

### 代码

```cpp
class Solution {
public:
    
    int minSetSize(vector<int>& arr) {
        map<int, int> mapCount;
        for (auto m : arr) {
            mapCount[m]++;
        }
        vector<int> v;
        for (auto it = mapCount.begin(); it!=mapCount.end(); it++) {
            v.emplace_back(it->second);
        }
        sort(v.begin(), v.end(), greater<int>());
        
        
        int count = (int)arr.size()/2;
        int index = 0;
        while (count > 0 ) {
            count -= v[index];
            index++;
        }
        return index;
    }
};
```