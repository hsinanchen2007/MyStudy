![截屏2020-03-2114.59.03.png](https://pic.leetcode-cn.com/6d5f2cb3f3b9ed450deb2a556e7982a966ca161db623bd08c6de39cba7f184d0-%E6%88%AA%E5%B1%8F2020-03-2114.59.03.png)

从空集合逐步扩张
{}
{}, 1
{}, 1, 2, 12
...

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{{}};
        for (int i = 0; i < nums.size(); ++i){
            build(res, nums[i]);
        }
        return res;
    }

    void build(vector<vector<int>>& res, int val ){
        int origin_size = res.size();
        for (int i = 0; i < origin_size; ++i){
            auto r = res[i];
            r.emplace_back(val);
            res.emplace_back(r);
        }
    }
};