- 282/282 cases passed (52 ms)
- Your runtime beats 79.43 % of cpp submissions
- Your memory usage beats 75.8 % of cpp submissions (9.3 MB)
```
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    set<vector<int>> s;
    sort(nums.begin(), nums.end());
    if (nums.size() < 4)
        return ans;
    for (int i = 0; i < nums.size() - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int p = j + 1, q = nums.size() - 1;
            while (p < q)
            {
                int res = nums[i] + nums[j] + nums[p] + nums[q];
                if (res == target)
                {
                    s.insert(vector<int>{nums[i], nums[j], nums[p], nums[q]});
                    p++;
                    q--;
                }
                else if (res < target)
                    p++;
                else
                    q--;
            }
        }
    }
    for (set<vector<int>>::iterator it = s.begin(); it != s.end(); it++)
        ans.push_back(*it);
    return ans;
}
```
