### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            //0 1 2 3 4 index
            //1 2 3 4 6 n = 5
            //6应该放在index = 5的地方 但是已经越界了，所有nums[i] > n 可以排除
            //根据题意  <= 0 的 和 > n的找不到合适的位置，所以直接跳过
            //原本考虑nums[i] - 1 != i; 就可以交换位置 更新为正确的位置
            //但是
            //0 1 index
            //1 1 n = 2
            //i = 1  nums[i] - 1 != i  -> 1 - 1 != 1  需要交换？ 按照这种规则 第2个1 需要放到index = 0的地方
            //会陷入死循环
            //所以我们不仅需要判断 位置对不对，还需要判断对的位置上 是不是 和 自己相同  相同也没必要交换了
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
```