嘻嘻嘻
![image.png](https://pic.leetcode-cn.com/d41ff12b36aa477459f168e47d433f2137b04339353e8b2f55cd05aeacdd81e5-image.png)

首先我们看一下这道题和39题，40题的区别
这道题说的是从1-9里面挑选k个数，和为n
也就是在40题的基础上加了一个条件k个数，数组则变成了[1,2,3,4,5,6,7,8,9]
```
class Solution {
    vector<vector<int>> res;
    vector<int> v;
    int k;


    void dfs(int remain, int start)
    {
        if(v.size() == k)
        {
            if(remain == 0)
                res.push_back(v);
            return;
        }
        if(remain < 0 || start > 9)
        {
            return;
        }


        for(int i = start; i <= 9; i++)
        {
            v.push_back(i);
            dfs(remain - i, i + 1);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int _k, int n) {
        k = _k;
        int sum = (1 + 9) * 9 / 2;
        if(k > 9 || n > sum) return res;//如果大于9个数说明是不可能的；9个数字总和也不能大于45
        dfs(n, 1);
        return res;
    }
};
```

