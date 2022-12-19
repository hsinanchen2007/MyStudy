**DFS + 回溯算法 + 剪枝，可以结合我的图和注释看代码，应该很容易理解**
**欢迎交流**

# 递归树 及 剪枝说明
![image.png](https://pic.leetcode-cn.com/0c9696e21d4b37f4767b68ce386ab2740a1f0b0c6c0ba8545cef7fb10a093363-image.png)

# 源码
```
vector<vector<int>> ans;
vector<vector<int>> combine(int n, int k) {
    vector<int>nums(n,{(1,n)}); for (int i = 0; i < n; i++) nums[i] = i + 1;//初始化
    recursion(nums, k, 0);													//DFS
    return ans;															    //返回
}
void recursion(vector<int>& nums, int k, int pos) {
    if (nums.size() == k){ ans.push_back(nums); return; }//若已找到 k 个值，记录并返回
    for (int i = pos; i < nums.size(); i++) {		     //否则，遍历子节点
        vector<int>tmp(nums);		//暂存：以备回溯
        nums.erase(nums.begin()+i);	//删除：至下一层节点
        recursion(nums, k, i);		//递归：DFS
        nums = tmp;	                //恢复：回溯	
    }
}
```

