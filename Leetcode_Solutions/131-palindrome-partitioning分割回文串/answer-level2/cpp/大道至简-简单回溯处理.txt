从题意中可以知道，我们需要判断回文串的子串是否为回文，

在这里我说一下**回溯和DFS**的区别：
  
(1)访问的次序不同：深度优先遍历的目的是“遍历”，本质是无序的，重要的是是否被访问过，因此在实现上只需要对于每个位置是否被访问就足够了。回溯法的目的是“求解过程”，本质是有序的，也就是说必须每一步都是要求的次序。
(2)访问次数不同：深度优先遍历对已经访问过的顶点不再访问。回溯法中已经访问过的顶点可能再次访问。
(3)剪枝不同：深度优先遍历不含剪枝。

实际上，除了剪枝是回溯法的一个明显特征外（并非任何回溯法都包含剪枝部分），很难严格区分回溯法 与深度优先遍历。因为这些算法很多是递归算法，在递归调用中隐含着状态的自动回退和恢复。
```
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        partitionHelper(s, result, path, 0);//回溯
        return result;
    }
     
private:
    void partitionHelper(const string &s, vector<vector<string>> &result, vector<string> &path, int pos) {
        // base case
        if (pos == s.size()) {
            result.push_back(path);
            return;
        }
         
        //DFS（类似深度优先遍历）
        for (int i = pos; i < s.size(); i++) {
            if (isPalindrome(s, pos, i)) {//判断从pos到i位置的子串是否为回文串
                path.push_back(s.substr(pos, i - pos + 1));//放入容器中
                partitionHelper(s, result, path, i + 1);//继续下一个
                path.pop_back();//回退到上一次的情况再次进行深度优先搜索
            }else return;
        }
    }
     
    bool isPalindrome(const string &s, int start, int end) {//判断字符串回文函数
        while (start < end) {
            if (s[start] == s[end]) {
                start++;
                end--;
            } else {
                break;
            }
        }      
        return start >= end;
    }
};
```
