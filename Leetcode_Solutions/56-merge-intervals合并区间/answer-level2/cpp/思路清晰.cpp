![图片.png](https://pic.leetcode-cn.com/d006794fa36c67b8d76e763286e19494cc394b79d5f5ebe78d9ce275f4c72b5b-%E5%9B%BE%E7%89%87.png)

### 解题思路
1. 排序
2. 遍历，每次merge一个

按每个区间的左区间排序，排完序之后每次merge只需要考虑已有结果集中最后一个vector和待merge的vector。
思路清晰。

### 代码

```cpp
bool sort_func(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sort_func);

        vector<vector<int>> res;
        for(int i = 0;i < intervals.size(); ++i)
        {
            merge_one(res, intervals[i]);
        }
        return res;
    }

    void merge_one(vector<vector<int>> &res, vector<int> &v)
    {
        if(res.empty()) 
        {
            res.push_back(v);
            return;
        }
        vector<int> &res_last = res.back();
        if(v[0] > res_last[1])
        {
            res.push_back(v);
        }
        else
        {
            res_last[0] = min(res_last[0], v[0]);
            res_last[1] = max(res_last[1], v[1]);
        }
    }
};

```