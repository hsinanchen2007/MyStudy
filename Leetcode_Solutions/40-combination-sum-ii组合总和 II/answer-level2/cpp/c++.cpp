### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
vector<vector<int>>res;
vector<int>path;
    void findcom(vector<int>& candidates, int now, int target)
    {
        if (target == 0)
        {
            res.push_back(path);
            return;
        }
        if (target < 0)
        {
            return;
        }
        if (now == candidates.size())
        {
            return;
        }
        path.push_back(candidates[now]);//加入第now个元素
        findcom(candidates, now+1, target - candidates[now]);//与前一题不同的是，不能取重复元素，因此只能从下一个即now+1处添加
        path.pop_back();

        while (now + 1 < candidates.size() && candidates[now] == candidates[now + 1])//对排序后的数组去重
        {
            now++;
        }
        findcom(candidates, now + 1, target);//不加入第now个，直接加入第now+1个元素。
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        findcom(candidates, 0, target);
        return res;
    }
};
```