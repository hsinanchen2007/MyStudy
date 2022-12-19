### 解题思路
此题是[全排列](https://leetcode-cn.com/problems/permutations/)的变体，重点是去重减枝。都是回溯算法。

回溯算法的解题步骤：

1. 确定解空间元素，也可以说是解路径上的各个节点取值。
2. 如何定义到达叶子节点，即找到问题的一个解
3. 对于每一个可行路径，判断当前节点是否能够加入到当前路径，利用减枝条件减枝，如果满足可行解条件加入路径，否则回溯到上一个节点，并且清楚当前节点记录信息。

### 全排列

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() < 2) return {nums};
        vector<int> decisions;
        backTrack(nums, decisions);
        return res;
        
    }
    //options: 可选路径
    //decisions: 已经选择的路径
    void backTrack(vector<int> &options, vector<int>& decisions) {
        if(decisions.size() == options.size()) {//终止条件： 到达叶子节点
            res.push_back(decisions);//找到一个解
            return;
        }
        for(int i : options) { //在可选路径中选择一条路径
            if(find(decisions.begin(), decisions.end(), i) == decisions.end()) { //此路是否走过
                decisions.push_back(i);//没走过，添加进来
                backTrack(options, decisions);//继续往下走
                decisions.pop_back();//换一条路看看有没有解
            }
            else 
                continue; //此路走过了，减枝
        }
    }
private:
    vector<vector<int>> res;
};
```

### 全排列II

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() < 2) return {nums};
        vector<int> decisions;//一条可行路径
        vector<int> visited(nums.size(), 0);//已访问节点
        sort(nums.begin(), nums.end()); //排序再去重是关键
        backTrack(nums, decisions, visited);//回溯算法
        return res;
        
    }
    //options: 可选路径
    //decisions: 已经选择的路径
    //visited: 已经访问过
    void backTrack(vector<int> &options, vector<int>& decisions, vector<int>& visited) {
        if(decisions.size() == options.size()) {//终止条件： 到达叶子节点
            res.push_back(decisions);//找到一个解
            return;
        }
        
        for(int i = 0; i < options.size();i++) { //在可选路径中选择一条路径
            if(visited[i] == 0) {//当前未访问过
                if(i > 0 && options[i] == options[i-1] && visited[i-1] != 0) continue;//当前节点和前一节点一样，并且前一个已经访问过了，就不用重复了。
                decisions.push_back(options[i]);
                visited[i] = 1;
                backTrack(options, decisions, visited);
                //到这说明当前节点不是可行解，换一条路，清除这个节点的记录信息
                visited[i] = 0;//去访问痕迹
                decisions.pop_back();//将当前节点从这个路径上去除
            }
        }
    }
private:
    vector<vector<int>> res;
};

```