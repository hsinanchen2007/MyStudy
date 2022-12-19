### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < size; i++) {
            mp[nums[i]] += 1;
        }

        for( const auto& n : mp ) {
            std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
            if(n.second > size / 2) {
                return n.first;
            }
        }

        return 0;
    }
};
```