可以利用dfs求得，dfs需要进行剪枝
这个分成4分，dfs的工作就是要知道每一个数字放在哪一部分呢？

![image.png](https://pic.leetcode-cn.com/d98c4428ce861bfc110f44dab1c5e958cca994c20adfcb62e12abab84618e8f9-image.png)
```
class Solution {
    vector<int> partition;
    int target;
    vector<int> nums;
    bool dfs(int idx)
    {
        if(idx == nums.size())
        {
            return (partition[0] == partition[1] && partition[1] == partition[2] && partition[2] == partition[3]);
        }
        for(int i = 0; i < 4; i++)
        {
            if(partition[i] + nums[idx] > target)
                continue;
            partition[i] += nums[idx];
            if(dfs(idx + 1))
                return true;
            partition[i] -= nums[idx];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& _nums) {
        nums = _nums;
        int sum = 0;
        if(nums.size() < 4)
            return false;
        for(auto x: nums)
            sum += x;
        if(sum % 4 != 0)
            return false;
        target = sum / 4;
        sort(nums.begin(), nums.end(),greater<int>());
        partition = vector<int>(4, 0);
        return dfs(0);
    }
};
```
