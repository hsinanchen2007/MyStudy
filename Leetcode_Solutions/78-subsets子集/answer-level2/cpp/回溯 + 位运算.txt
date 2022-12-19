## 回溯法

```C++ []
class Solution {
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, int start, vector<int>& nums){
        ans.push_back(curr);
        
        for(int i = start; i < nums.size(); i++){
            curr.push_back(nums[i]);
            backtrack(ans, curr, i + 1, nums);
            curr.pop_back();
            
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, curr, 0, nums);
        return ans;
    }
};

```
第一种就是类似之前题目中的回溯法，之前题目是在当前序列到达一定长度才加入解中，而这次是任意长度都加入解中。


## 位运算

```C++ []
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < 1 << n; i++){
            vector<int> curr;
            for(int j = 0; j < n; j++){
                if(i >> j & 1 == 1)
                    curr.push_back(nums[j]);
            }
            ans.push_back(curr);
        }
            
        return ans;
    }
};

```

感觉这个方法挺秀的。

具体思路就是对于一个大小为n且没有重复元素的数组，他的子集一共有$2^n$个，而且每一个整数对应的二进制数都可以表示为一个子集（其中1代表取这个位置的数，0代表不取）。对于一个二进制数0011（假装四位），如果向右移动j位并且和1通过 & 运算能够得到1的话，说明这个数的第j位为1那么把nums[j]加入当前解中就好了