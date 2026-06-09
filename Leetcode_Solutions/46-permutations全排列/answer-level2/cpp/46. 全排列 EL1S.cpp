全排列 总数是 3!

[17题](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/17-dian-hua-hao-ma-de-zi-mu-zu-he-el1s-by-uqisn4nw/)可以使用两种方式解决。
但是这道题和17题不同的是，17题每一个位置能够选择的东西都是不同的，但是这道题，每一个位置能选择的东西是一样的，不放回的抽取。
如果使用循环来做就需要把前面位用过的数字都先排除掉。
这道题没法使用循环，因为如果是某一位用某一个数字，然后再继续枚举这一位用别的数字，这个state状态岂不是同时置位了多个位？

如果说每一个位置互不干扰，那就能使用循环来做，例如：

![image.png](https://pic.leetcode-cn.com/6046d945a68cd77626ae18e3dce8bce872ff21940d2645159f0428f1e7ff0edb-image.png)

```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v1(1), v2;
        for(int i = 0; i < nums.size(); i++)//第几个位置
        {              
            for(int k = 0; k < v1.size(); k++)//和原来有的可能进行拼接
            {
                for(int j = 0; j < nums.size(); j++)//有几种可能 如果这个在外层 那么就会连着加了好几层
                {
                    vector<int> tmp = v1[k];
                    tmp.push_back(nums[j]);
                    v2.push_back(tmp);
                }

            }
            v1 = v2;
            v2.clear();
        }
        return v1;
    }
};
```

对于这道题，解法可以用dfs来做，代码如下：
```
class Solution {
    vector<int> nums;
    vector<vector<int>> res;
    vector<int> v;
    void dfs(long long state, long long last)
    {
        if(state == ((1 << nums.size()) - 1))
        {
            res.push_back(v);
            return;
        }
        for(long long i = 0; i < nums.size(); i++)
        {
            if(!((1 << i) & state))
            {
                state ^= (1 << i);
                v.push_back(nums[i]);
                dfs(state, nums[i]);
                state ^= (1 << i);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& _nums) {
        nums = _nums;
        long long state = 0, last = 0;
        sort(nums.begin(), nums.end());
        dfs(state, last);
        return res;
    }
};
```
