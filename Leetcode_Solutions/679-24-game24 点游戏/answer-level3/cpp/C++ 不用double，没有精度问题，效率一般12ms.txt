### 解题思路
递归还是比较清晰，主要区别是我这里用 {被除数，除数} 来表示所有数字，这样可以避免double的精度问题，但是增加了很多计算，效率会比double法偏低。

### 代码

```cpp
class Solution {
public:
    using Number = pair<int, int>;

    bool judgePoint24(vector<int>& nums) {
        if (nums.size() == 0) return false;
        vector<Number> leftnums;
        for (int i : nums) leftnums.push_back({i, 1});
        return recursive(leftnums);
    }

    bool recursive(vector<Number>& nums)
    {
        if (nums.size() == 1)
        {
            if (nums[0].first % nums[0].second != 0) return false;
            return nums[0].first / nums[0].second == 24;
        }

        vector<Number> leftnums;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                fillleft(leftnums, nums, i, j, plus);
                if (recursive(leftnums)) return true;

                fillleft(leftnums, nums, i, j, minus);
                if (recursive(leftnums)) return true;
                fillleft(leftnums, nums, j, i, minus);
                if (recursive(leftnums)) return true;

                fillleft(leftnums, nums, i, j, multiply);
                if (recursive(leftnums)) return true;

                if (!iszero(nums[j]))
                {
                    fillleft(leftnums, nums, i, j, div);
                    if (recursive(leftnums)) return true;
                }
                if (!iszero(nums[i]))
                {
                    fillleft(leftnums, nums, j, i, div);
                    if (recursive(leftnums)) return true;
                }
            }
        }
        return false;
    }

    void fillleft(vector<Number>& leftnums, vector<Number>& nums, int a, int b, Number (*func)(const Number&,const Number&))
    {
        leftnums.clear();
        leftnums.push_back(func(nums[a], nums[b]));
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == a || i == b) continue;
            leftnums.push_back(nums[i]);
        }
    }

    bool iszero(const Number& num)
    {
        return num.first == 0;
    }

    static Number plus(const Number& a, const Number& b)
    {
        Number res;
        res.first = a.first * b.second + a.second * b.first;
        res.second = a.second * b.second;
        return res;
    }

    static Number minus(const Number& a, const Number& b)
    {
        Number res;
        res.first = a.first * b.second - a.second * b.first;
        res.second = a.second * b.second;
        return res;
    }

    static Number multiply(const Number& a, const Number& b)
    {
        Number res;
        res.first = a.first * b.first;
        res.second = a.second * b.second;
        return res;
    }

    static Number div(const Number& a, const Number& b)
    {
        Number res;
        res.first = a.first * b.second;
        res.second = a.second * b.first;
        return res;
    }
};
```