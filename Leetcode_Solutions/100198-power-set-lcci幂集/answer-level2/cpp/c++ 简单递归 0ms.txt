![捕获.PNG](https://pic.leetcode-cn.com/1c38c90f784514991a75db4d6eb9ba575c513798c9007c022733bb51a593290f-%E6%8D%95%E8%8E%B7.PNG)

```c++
//更新了一种更为简洁的写法
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return powerset(nums,0);
    }

    vector<vector<int>> powerset(const vector<int>& nums,int be){
        if(be>=nums.size())return {{}};
        auto vv=powerset(nums,be+1);
        int oldsize=vv.size();
        for(int i=0;i<oldsize;i++){
            vector<int> v=vv[i];
            v.push_back(nums[be]);
            vv.push_back(v);
        }
        return vv;
    }
};

//以前的写法。。
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        addsubset_begin_with_be(nums,ans,0);//
        return ans;
    }

    void addsubset_begin_with_be(const vector<int>& nums,vector<vector<int>>& ans,int be){//把从be开始的后面数据的所有子集加到ans里面
        if(be==nums.size()-1){
            ans.push_back(vector<int>());
            ans.push_back(vector<int>{nums.back()});
            return;
        }
        addsubset_begin_with_be(nums,ans,be+1);
        int size=ans.size();
        for(int i=0;i<size;i++){
            vector<int> v(ans[i]);
            v.push_back(nums[be]);
            ans.push_back(v);
        }
    }
};
```