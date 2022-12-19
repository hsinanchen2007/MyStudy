### 读题
- 有重复元素，解需要注意去重
- 可能无解，返回空数组
- 返回解而不是下标

### 解题思路
C++ 排序+双指针

- 首先排序O(NlogN)
- i一次遍历，最坏时间复杂度O(N)
- LR双指针从(i+1,size-1)处向内收缩，O(N)
- 综合起来最坏复杂度O(N^2)

代码中有几处细节很容易错，已注释标出。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        int n = nums.size();
        if (n<3) return ans; //特判：少于3个元素的返回空vector

        sort(nums.begin(), nums.end());

        for (int i=0; i<n; ++i) {
            if (nums[i] > 0) return ans; //i处大于0，和一定大于0，结束运算
            if (i>0 && nums[i]==nums[i-1]) continue; //i重复，直接跳过

            int L = i+1;
            int R = n-1;
            while (L<R) {
                if (nums[L]+nums[R]<-nums[i]) L++;
                else if (nums[L]+nums[R]>-nums[i]) R--;
                else {
                    ans.push_back({nums[i],nums[L],nums[R]});
                    L++; //此处容易遗漏：双指针要迭代完整个(i+1,n-1)数组，可能不止一个解答
                    R--;
                    while (L<R && nums[L]==nums[L-1]) L++; //分别去除两边指针可能的下一个重复
                    while (L<R && nums[R]==nums[R+1]) R--; //这里L和R已经迭代了一步，+-容易错
                }
            }
        }
        return ans;
    }
};
```