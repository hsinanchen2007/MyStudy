### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        int size = nums.size();
        unordered_set<int> up;

        for(int i = 0; i< size; i++) {
            up.insert(nums[i]);
        }

        int max_value = *max_element(nums.begin(), nums.end());

        for(int i = 1; i <= max_value; i++) {
            if(up.find(i) == up.end()){
                return i;
            }
        }

        return max_value > 0 ? max_value + 1 : 1;
    }
};
```


165 / 165 个通过测试用例
状态：通过
执行用时：4 ms
内存消耗：11.7 MB