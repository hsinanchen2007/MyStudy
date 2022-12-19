```
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) 
    {
        int small = 1;
        int big = 2;
        int mid = (1 + target) / 2;
        int cur_sum = small + big;

        while(small < mid)
        {
            if(cur_sum == target) output_nums(small, big);

            while(cur_sum > target && small < mid)
            {
                cur_sum -= small;
                ++small;
                if(cur_sum == target) output_nums(small, big);
            }
            ++big;
            cur_sum += big;
        }
        return res_vecs;
    }

    void output_nums(int small, int big)
    {
        vector<int> res;
        for(int i = small; i <= big; ++i) res.push_back(i);
        res_vecs.push_back(res);
    }

private:
    vector<vector<int>> res_vecs;
};
```
