### 解题思路
先放大的，这样能更快到终点。

### 代码

```cpp
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        for(auto num : nums)
            sum += num;
        if(sum % 4)
            return false;
        sum /= 4;
        for(auto num : nums)
            if(num > sum)
                return false;
        sort(nums.begin(), nums.end(), greater<int>{});
        DFS(nums, 0, 0, 0, 0, 0);
        return flag;
    }
    void DFS(vector<int>& nums, int now, int cnt1, int cnt2, int cnt3, int cnt4)
    {
        if(now == nums.size())
        {
            if(cnt1 == cnt2 && cnt2 == cnt3 && cnt3 == cnt4)
                flag = true;
            return ;
        }
            if(cnt1 + nums[now] <= sum && !flag)
                DFS(nums, now + 1, cnt1 + nums[now], cnt2, cnt3, cnt4);
            if(cnt2 + nums[now] <= sum && !flag)
                DFS(nums, now + 1, cnt1, cnt2 + nums[now], cnt3, cnt4);
            if(cnt3 + nums[now] <= sum && !flag)
                DFS(nums, now + 1, cnt1, cnt2, cnt3 + nums[now], cnt4);
            if(cnt4 + nums[now] <= sum && !flag)
                DFS(nums, now + 1, cnt1, cnt2, cnt3, cnt4 + nums[now]);
    }
private:
    bool flag =false;
    int sum = 0;
};
```