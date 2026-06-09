### 哈希他不香吗
遍历计数，选择输出

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int,int>hash;
        for(int i = 0;i < nums.size();i++)
        {
            hash[nums[i]]++;
        }
        return hash[target];
    }
};
