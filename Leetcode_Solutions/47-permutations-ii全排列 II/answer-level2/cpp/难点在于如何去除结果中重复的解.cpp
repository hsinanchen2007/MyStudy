### 解题思路
本体与 [全排列](https://leetcode-cn.com/problems/permutations/) 相似， 但是难点在于如何去除结果中重复的解， 最简单粗暴的方法就是在 [全排列](https://leetcode-cn.com/problems/permutations/) 最后 return 前使用最差为 O(n²) 的时间复杂度的算法去重。 但是可以有更好的解法， 那就是在回溯的过程中进行剪枝。
这种需要让结果中的解不重复的题目基本上都需要先将输入的元素进行排序， 因为需要让相同的元素聚在一起然后才能以此将相同的元素进行剪枝， 下面就是分析会产生重复解的地方， 通过画图可以发现产生重复解的地方都是连续 2 个以上的元素相同第二个元素开始(如 nums =  [1, 1, 2] , nums[1] 位置的 1)，向前选择的过程中(例如解中 第一个元素为 nums[1] 位置的 1， 第二个元素为 nums[0] 位置的 1) 的位置。 也可以理解为两个或以上的相同的元素， 其不重复的组合只有一种， 也就是第一个重复的元素开始的解， 一定包含以后面重复的元素为开始的解。 这也就是要对非起始重复元素与前一个相同的进行剪枝 即 i > 0 && nums[i] == nums[i - 1]。
但是 nums[i] == nums[i - 1] 有一个陷阱， 就是要对 nums[i] == nums[i - 1] 进行剪枝的地方实际上是回溯后进行选择的地方， 而不是应该是选取下一个元素时， 因为本题中属于元素就是包含重复元素的也就是说结果中可以出现两个相同的元素， 所以在进行元素选择(也就是进入递归树的下一层的时候， 允许 nums[i] == nums[i - 1])， 判断是进入下一层， 还是回溯完可以通过 used[i - 1] 判断， used[i - 1] == false 说明是回溯完过来的(上一次循环因为有个 used[i] = false 的操作)
所以最终剪枝的判断就为 i > 0 && nums[i] == nums[i - 1] && !used[i - 1]

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permutes;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size() ,false);
        __permute(nums, used, tmp);
        return permutes;
    }
private:
    // 基本思路就是遍历回溯一棵树， 树的每一层的宽度就是 nums 的每一个元素， 并且深度就是 nums 的个数 
    // nums: 原数组
    // nums: 原数组哪些位置在本分之上之前被使用用
    // tmp： 保存中间的结果
    void __permute(vector<int>& nums, vector<bool> used, vector<int> tmp){
        if(tmp.size() == nums.size()){
            permutes.push_back(tmp);
        }else{
            for(int i = 0; i < nums.size(); i++){
                if(!used[i]){
                    if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                        continue;
                    }
                    cout << 1;
                    tmp.push_back(nums[i]);
                    used[i] = true; // 每个数子只能使用一次， 在进行下一层递归时需要知道当前位置的元素已经被使用过
                    __permute(nums, used, tmp);
                    tmp.pop_back();
                    used[i] = false; // 只需要让下一层知道对应位置被使用过， 同一层级的实际上使用的是其他位置的元素
                }
            }
        }
    }
};
```