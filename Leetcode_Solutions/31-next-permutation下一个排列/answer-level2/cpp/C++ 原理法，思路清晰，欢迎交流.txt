C++，
执行用时 :8 ms, 在所有 C++ 提交中击败了98.14%的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了94.58%的用户

![图片1.png](https://pic.leetcode-cn.com/3ba7805abafcd0092b19ce7b5b873e922b7b7ce385eb445e3e9a882719e2cf01-%E5%9B%BE%E7%89%871.png)

```
bool isMax(vector<int>& nums, int i) {	//从i的下一个位置开始，判断是否为最大排列
    if (i + 1 == nums.size() - 1) return 1;
    for (int k = i + 2; k < nums.size(); k++)
        if (nums[k] > nums[k - 1])
            return 0;
    return 1;
}
int findNext(vector<int>& nums, int i) { //从i的下一个位置开始，寻找“恰好”比nums[i]大的值
    int tmp = INT_MAX, res = i;
    for (int k = i + 1; k < nums.size(); k++)
        if (nums[k] > nums[i] && nums[k] <= tmp) { 
            res = k;                               
            tmp = nums[k];                         
        }                                          
    return res;
}
void nextPermutation(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (!isMax(nums, i)) continue;			  //若第i位后面不构成最大排列，则i位不用动
        int next_pos = findNext(nums, i);		  //找到比nums[i]恰好大的值的位置
        if (next_pos == i) reverse(nums.begin() + i, nums.end());//若没有比其大的，直接反转
        else {									  //若有恰好比其大的，交换之后再反转
            nums[i] ^= nums[next_pos];
            nums[next_pos] ^= nums[i];
            nums[i] ^= nums[next_pos];
            reverse(nums.begin() + i + 1, nums.end());
        }
        break;									  //游戏结束
}
```

