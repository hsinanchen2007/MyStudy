### 解题思路
由于数组值范围确定1~N，故使用值作为数组下标，统计值出现的情况，存储于结果集中
最终结果集中值为0的，其对应的索引即为缺失的数
最后调整返回结果集的大小
### 代码

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }
        vector<int> v(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            v[nums[i]] = 1;
        }
        int idx = 0;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] == 0) {
                v[idx] = i;
                ++idx;
            }
        }
        v.resize(idx);
        return v;
    }
};
```