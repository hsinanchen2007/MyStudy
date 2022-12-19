### 解题思路
这道题目步骤为： 排序 -> DFS -> 去重
如果使用set<vector<int>, int>或者map<vector<int>, int>去做，时间空间复杂度过高

这道题难点在于去重，对于无重复元素的vector，很简单，只要使用一个hash(vector<int>)，表征某个元素是否被访问过即可。
这道题是加强版，存在重复元素，并且不要求重复数组
也就是[1,1,2]，如果沿用无重复元素的做法，结果为
[[1,1,2],[1,2,1],[1,1,2],[1,2,1],[2,1,1],[2,1,1]]

如果我们使用1a,1b区分两个1，那么结果是
[[1a,1b,2],[1a,2,1b],[1b,1a,2],[1b,2,1a],[2,1a,1b],[2,1b,1a]]

我在去重的时候，想到第一个条件是i > 0 && nums[i] = nums[i-1]即为重复。
但是对于这个case，如果加在DFS每一层中，这个case结果为[]

其实重复的条件比这个条件还要再难一点，我们思考一个问题，怎么样为重复？
- 首先一定满足i > 0 && nums[i] = nums[i-1], 说明重复(遍历是从左往右)
- 此外，**如果nums[i]被访问的时候，nums[i-1]还没有被访问过，这就是重复！！！**也是这道题的关键
- 比如，上面的例子，1b被访问的时候，如果1a没有被访问过，那么table里面的val为0，那么后面就会被访问，这样就会出现重复
- 所以，对于table[i-1] == 0，这些case，都是重复case，需要剪掉。加上这个条件之后就可以pass


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> table(nums.size(), 0);
        vector<int> combination;
        getCombination(res, nums, combination, table);
        return res;
    }

    void getCombination(vector<vector<int>> &res, vector<int>& nums, vector<int>& combination, vector<int> &table){
        if(combination.size() >= nums.size()){
            res.push_back(combination);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(table[i] == 1) continue;
            if(i > 0 && nums[i] == nums[i-1] && table[i-1] == 0) continue;
            combination.push_back(nums[i]);
            table[i] = 1;
            getCombination(res, nums, combination, table);
            combination.pop_back();
            table[i] = 0;
        }
    }
};
```

### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 97.61% 的用户 
内存消耗 : 7.7 MB , 在所有 C++ 提交中击败了 100.00% 的用户