 * 回溯算法框架：解决一个问题，实际上就是一个决策树的遍历过程：
 * 1. 路径：做出的选择
 * 2. 选择列表：当前可以做的选择
 * 3. 结束条件：到达决策树底层，无法再做选择的条件
 
class Solution {
public:
    vector<string> permutation(string s) {
        set<string> temp;
        backtrack(s, 0, temp);
        vector<string> ans(temp.begin(), temp.end());
        return ans;
    }

    void backtrack(string s, int start, set<string>& temp) {
        if (start == s.size() - 1){
            temp.insert(s);
            return ;
        }
        for (int i = start; i < s.size(); i++) {
            swap(s[start], s[i]);
            backtrack(s, start + 1, temp);
            swap(s[start], s[i]);
        }
    }
};