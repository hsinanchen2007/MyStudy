### 解题思路
![image.png](https://pic.leetcode-cn.com/772876ae28d8a7647322105b6a824f86ae045ab56387da16f9b9e4d52760b912-image.png)
（套路之外，初始化minDiff为一个很大的值，int最大是10^9左右。用ans保存最终答案。）
第一步，排序，方便之后的剪枝移动。
第二步，固定最左边的指针，保证另外两个指针不与之重合。
第三步，两个指针从左右向中间移动，每次移动都判断当前和与目标的差值是否比minDiff更小。如果是，更新minDiff和ans。
一个优化点，如果当前和已经等于目标，则差值不可能跟小了，直接返回ans。


### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int minDiff = 100000000;
        if (nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int now = nums[i] + nums[left] + nums[right];
                if (abs(now - target) < minDiff) {
                    minDiff = abs(now - target);
                    ans = now;
                    if (ans == target) return ans;
                }
                if (now < target) ++left;
                else --right;
            }
        }
        return ans;
    }
};
```