### 执行时间
![图片.png](https://pic.leetcode-cn.com/b3f32e06784998e4152de8067fd57b62485811cb249c26b856dfad63d212a856-%E5%9B%BE%E7%89%87.png)

### 思路
1. 排序
2. 算和，除以 4 算每条边的长度
3. 从后往前回溯 4 次

### 答题
```C++ []
bool dfs(vector<int>& nums, vector<bool>& vi, int idx, int sum)
{
    if (sum == 0) return true;
    if (idx < 0) return false;

    for (int i = idx; i >= 0; i--)
    {
        if (vi[i]) continue;
        if (sum < nums[i]) continue;

        vi[i] = true;
        if (dfs(nums, vi, i - 1, sum - nums[i])) return true;
        vi[i] = false;
    }
    return false;
}

bool makesquare(vector<int>& nums) 
{
    if (nums.size() < 4) return false;
    sort(nums.begin(), nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 4 != 0) return false;
    sum /= 4;
        
    vector<bool> vi(nums.size(), false);
    for (int i = 0; i < 4; i++)
    {
        if (!dfs(nums, vi, nums.size() - 1, sum)) return false;
    }
    return true;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

