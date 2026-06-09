### 解题思路
将数组内所有递增子序列的长度保存进set，set中最后一位元素的值即为最大长度，所以返回set中最后一个元素的值即可。注意要判断空数组的情况。
执行用时 :12 ms, 在所有 cpp 提交中击败了91.33%的用户
内存消耗 :9.2 MB, 在所有 cpp 提交中击败了95.44%的用户

### 代码

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int length = 1;
        set<int> lset;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] < nums[i+1]) {
                length++;
            }
            else {
                lset.insert(length);
                length = 1;
            }
        }
        lset.insert(length);
        auto it = lset.end();
        return *(--it);
    }
};
```