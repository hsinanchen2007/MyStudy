
/*
1：仔细审题：nums中的元素一定在lower、upper范围之内
2：nums中相邻元素不连续的地方就是缺失区间
3：用例中有INT_MIN和INT_MAX的老梗
*/
```
class Solution {
public:
    inline string Idx2Str(long long index)
    {
        stringstream s;
        s<<index;
        return s.str();
    }

    string GetRes(long long l, long long r)
    {
        string res;
        if (l == r) {//只有一个数的情况
           res = Idx2Str(l);
           return res;
        } 
        
        res = Idx2Str(l);
        res += "->";
        res += Idx2Str(r);
       
        return res;
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        std:ios::sync_with_stdio(false);
        vector<string> ans;
        if (nums.size() == 0) {
            ans.push_back(GetRes(lower, upper));
            return ans;
        }

        if (nums[0] > lower) {
            string tmp = GetRes(lower, nums[0] - 1);//nums[0]前面那一截
            ans.push_back(tmp);
        }

        for (long long i = 0; i < nums.size() - 1; ++i) {
            /*相邻俩数，前一个加1还是比后一个小，那肯定是有间隙了(1 + 1 < 3但1 + 1 == 2，说明1,3有间隙)
            间隙区间就是比nums[i]大1的数到比nums[i + 1]小1的数*/
            if((long long)nums[i] + 1 < nums[i + 1]) {
                string tmp = GetRes(nums[i] + 1, nums[i + 1] - 1);
                ans.push_back(tmp);
            }
        }
        
        if (nums[nums.size() - 1] < upper) {
            string tmp = GetRes(nums[nums.size() - 1] + 1, upper);//最后面那一截
            ans.push_back(tmp);
        }
        
        return ans;
    }
};
```
