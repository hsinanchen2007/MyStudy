### 解题思路
joshua分享：用multiset保存中间的元素，左边删一个，右边加一个

### 代码

```cpp
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        if(k <= 0 || nums.empty()) return ans;
        // 首先把 k 个元素保存到集合中
        multiset<long long int > mSet(nums.begin(), nums.begin() + k);
        // 依次检测每一个后续的元素
        for(int i = k;; i++) {
            // 取出中间位置的那个元素
            auto mid = next(mSet.begin(), (k-1)/2);
            // 需要考虑 k 是奇数还是偶数，需要做一个 1 - k%2的计算
            ans.push_back( ( *mid + *next(mid, 1 - k%2) ) * 0.5 );

            if(i == nums.size()) break;
            // 删除最左边的那一个元素（只删除一次）
            mSet.erase(mSet.lower_bound(nums[i-k]));
            // 加入最右边的那一个元素
            mSet.insert(nums[i]);
        }
        return ans;
    }
};
```