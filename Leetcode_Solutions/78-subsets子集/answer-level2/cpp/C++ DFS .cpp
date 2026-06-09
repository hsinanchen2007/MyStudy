可以理解为任意K 点均可达的连图子图的求解！！！
```
class Solution {
public:
    void DFS(int index, vector<int>& nums, vector<bool>& visit, vector<int>& temp, vector<vector<int>>& path) {
        // 枚举所有节点，进入更新当前节点的子序列
        visit[index] = true;
        path.push_back(temp);
        // 递归边界：当前节点处理到
        if (index == nums.size()) {
            return;
        }
        for (int j = index; j < nums.size(); j++) {
            if (visit[index] == true) {
                temp.push_back(nums[j]);
                // 选择下一个节点
                // 节点存在选择或者不选择的场景
                DFS(j + 1, nums, visit, temp, path);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> path;
        vector<bool> visit(nums.size(), false);
        for (int i = 0; i < nums.size(); i++) {
            if (visit[i] == false) {
                DFS(i, nums, visit, temp, path);
            }
        }
        return path;
    }
};
```
