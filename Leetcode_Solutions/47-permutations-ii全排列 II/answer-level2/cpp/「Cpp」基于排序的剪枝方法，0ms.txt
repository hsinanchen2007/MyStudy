### 解题思路

关键代码为下面两行

```cpp
sort(nums.begin(), nums.end());
if ( i> 0 && nums[i] == nums[i-1] && ! used[i-1] ) continue;
```

以1211为例，排序之后是1112。为了方便区别，我们记为1'1''1'''2

每次选择下一个数的时候，我们有一个剪枝标准， 当前选择的数和之前的一样，并且之前的数没有被选择。举个例子

当我们选了1'之后，接下来有三个选择

- 1''
- 1'''
- 2

我们很容易看出来1''和1'''是一样的，我们其实只有2个选择。

当我们选完1''(i=1)之后，并一路走到底之后。之后我们有回溯到1'的路口，此时我们要选择1'''(i=2), 那我们就判断下这个数组是不是和之前的一样，同时**之前的数还没有被选择的话**，我们在选择这条路结果会是一样。

如果之前的数已经被选择了，那我们其实在1'1''这个路口，我们选择1'''是没有问题。


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
         //输出结果
        vector<vector<int>> ret;
        //表示使用状态
        vector<bool> used(nums.size(), false);
        //当前的组合
        vector<int> perm(nums.size());
        generate(0, perm, nums, used, ret);

        return ret;

    }
    /* 参数说明:
    * depth: 表示当前的深度
    * perm: 当前的组合
    * nums: 给定的数组
    * used: 使用情况
    */
    void generate(int depth, vector<int>&perm, vector<int>& nums, vector<bool>& used, vector<vector<int>>& ret){
        if ( depth == nums.size() ) {
            ret.push_back( perm );
            return ;
        }
        // 做选择
        for(int i = 0; i < nums.size(); i++){
            // 当前数字没有被使用, 没有用过是false
            if (  used[i] ) continue;
            if ( i> 0 && nums[i] == nums[i-1] && ! used[i-1] ) continue;

            used[i] = true;
            perm[depth] = nums[i];
            generate(depth+1, perm, nums, used, ret);
            //重置状态
            used[i] = false;
            

        }

    }
};
```

![image.png](https://pic.leetcode-cn.com/cfda0425c86c79255d79f46f6812e15b5088982e2aabcab2a71004cf22792fb7-image.png)
