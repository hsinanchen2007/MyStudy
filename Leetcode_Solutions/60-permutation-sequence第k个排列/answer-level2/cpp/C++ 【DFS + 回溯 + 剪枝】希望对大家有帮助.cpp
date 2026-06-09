![image.png](https://pic.leetcode-cn.com/8a76fba2c8b1a1e08a7d8f41d7919c20c7fbf9fc5ed1df1b6ea93138df0e8bbd-image.png)

# 方法一：调用31题函数
```
void nextPermutation(vector<int>& nums) {//31题函数
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;
    if (i >= 0) {									
        int j = nums.size() - 1;
        while (j >= 0 && nums[j] <= nums[i]) j--;
        nums[i] ^= nums[j]; nums[j] ^= nums[i]; nums[i] ^= nums[j];
    }
    reverse(nums.begin() + i + 1, nums.end());
}
string getPermutation(int n, int k) {
    string ans;
    vector<int>ivec;
    for (int i = 1; i <= n; i++) ivec.push_back(i);
    for (int i = 1; i < k; i++) nextPermutation(ivec);
    for (int i = 0; i < ivec.size(); i++) ans.push_back(ivec[i] + '0');
    return ans;
}
```

# 方法二：DFS + 回溯
```
void backtrack(vector<int>&nums, int i,int& k) {//k:距离目标还剩几个情况  
    if (i == nums.size())
        if (k-- == 0)
            return;
    for (int j = i; j < nums.size(); j++) {
        vector<int>tmp(nums);
        int jj = j;
        while (jj > i) { swap(nums[jj], nums[jj - 1]); jj--; }//交换
        backtrack(nums, i + 1, k);
        if (k == 0) return;
        nums = tmp;	//回溯(恢复）
    }
}
string getPermutation(int n, int k) {
    string ans;
    vector<int>ivec;
    for (int i = 1; i <= n; i++) ivec.push_back(i);
    int x = 0;
    backtrack(ivec, 0, k);
    for (int i = 0; i < ivec.size(); i++) ans.push_back(ivec[i] + '0');
    return ans;
}
```

# 方法三：DFS + 回溯 + 剪枝
```
vector<int>factorial{ 1,1,2,6,24,120,720,5040,40320,362880 }; //阶乘字典
void backtrack(vector<int>&nums, int i, int& k) {	//k:距离目标还剩几个 
    if (i == nums.size())
        if (k-- == 0)
            return;
    for (int j = i; j < nums.size(); j++) {
        if (k > factorial[nums.size() - i - 1]) {	//若当前节点下的叶子节点数>k，直接跳过
            k -= factorial[nums.size() - i - 1];
            continue;
        }
        vector<int>tmp(nums);
        int jj = j;
        while (jj > i) { swap(nums[jj], nums[jj - 1]); jj--; }//交换
        backtrack(nums, i + 1, k);
        if (k == 0) return;
        nums = tmp;	//回溯(恢复）
    }
}
string getPermutation(int n, int k) {
    string ans;
    vector<int>ivec;
    for (int i = 1; i <= n; i++) ivec.push_back(i);
    int x = 0;
    backtrack(ivec, 0, k);
    for (int i = 0; i < ivec.size(); i++) ans.push_back(ivec[i] + '0');
    return ans;
}
```
