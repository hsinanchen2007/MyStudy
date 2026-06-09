### 解题思路
先对数组排序，使相等的数相邻。
每个数有“取”和“不取”两个分支，结果对应了一个二叉树，我用0来表示这个数“不取”，画红x的是重复的子集
![image.png](https://pic.leetcode-cn.com/fa4bb8efdbb16af344f40fb674770a19530f8b0a1c42bcc0df6013498ff3612d-image.png)

当一个数走“取”这条分支（边上的数为0），那么下一个数的两个分支都要处理；
如果这个数“不取”（边上的数**不**为0），那么下一个数如果和它相等的话就只要处理“不取”的情况

### 代码
用一个flag来表示上一个数是否取进来，如果取进来了就分别处理当前数的两种情况
如果上一个数没取进来，而且当前数等于上一个数，则忽略取的情况，直接处理不取的情况。

```cpp
class Solution {
private:
vector<vector<int>> res;
vector<int> temp;

public:
    void DFS(int t,vector<int>&nums,bool isPushed,int pre){    
        if(t==nums.size()){
            res.push_back(temp);
            return;
        }
        if(isPushed||nums[t]!=pre){
            temp.push_back(nums[t]);
            DFS(t+1,nums,true,nums[t]);
            temp.pop_back();
        }

        DFS(t+1,nums,false,nums[t]);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        DFS(0,nums,true,-1000000);
        return res;
    }
};
```