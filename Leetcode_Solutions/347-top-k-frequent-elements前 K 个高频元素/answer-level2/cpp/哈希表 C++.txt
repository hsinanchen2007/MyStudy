### 解题思路
此处撰写解题思路
哈希表思想，将映射倒转一次即可。
### 代码

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m_map;
        multimap<int, int> r_map;
        for (int i = 0; i < nums.size(); i++) {
            m_map[nums[i]]++;
        }

        for (map<int, int>::iterator it = m_map.begin(); it != m_map.end(); it++) {
            r_map.insert(std::pair<int, int>(it->second, it->first));
        }
        vector<int> output;
        map<int, int>::iterator temp = r_map.end();
        temp--;
        for (int i = k; i > 0; i--) {
            output.push_back(temp->second);
            if (temp != r_map.begin()) {
                temp--;
            }
        }
        return output;
    }
};
```