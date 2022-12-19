### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 结果数组，保存全排列
        vector<vector<int>> res;
        // 保存一个排列
        vector<int> re;
        // 保存深度搜索到nums的哪一个index，等于0表示未搜索到，等于1表示已经搜索到
        vector<int> used(nums.size(), 0);
        // 深度搜索
        dfs(res, re, used, nums);
        return res;
    }

    // 回溯法，递归进行dfs
    // 参数1，结果数组；参数2，一个排列；参数3，深度搜索index，参数4:需要进行全排列的数组
    void dfs(vector<vector<int>>& res, vector<int>& re, vector<int>& used, vector<int>& nums) {
        // 如果re是一个排列，则push进结果数组末尾
        if(re.size() == nums.size()) {
            res.push_back(re);
            return;
        }
        // 一个排列遍历
        for(int i = 0; i < nums.size(); i++) {
            // 搜索过的index就跳过
            if(used[i] != 0)  continue;
            else {
                // 排列数组末尾push当前元素
                re.push_back(nums[i]);
                // 标记搜索过
                used[i] = 1;
                // 递归dfs
                dfs(res, re, used, nums);
                // 递归完了，进行回溯，进入下一个i的循环
                re.pop_back();
                used[i] = 0;
            }
        }
    }
};


#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& res, vector<int>& re, vector<int>& used, vector<int>& nums) {
    if(re.size() == nums.size()) {
        res.push_back(re);
        return;
    }
    for(int i = 0; i < nums.size(); i++) {
        if(used[i] != 0)  continue;
        else {
            re.push_back(nums[i]);
            used[i] = 1;
            dfs(res, re, used, nums);
            re.pop_back();
            used[i] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    // 结果数组，保存全排列
    vector<vector<int>> res;
    // 保存一个排列
    vector<int> re;
    // 保存深度搜索到nums的哪一个index，等于0表示未搜索到，等于1表示已经搜索到
    vector<int> used(nums.size(), 0);
    // 深度搜索
    dfs(res, re, used, nums);
    return res;
}

int main() {
    vector<int> v = {1, 2, 3};
    vector<vector<int>> res = permute(v);
    for (int i=0; i<res.size(); i++) {
        vector<int> temp = res[i];
        for (int j=0; j<temp.size(); j++) {
            cout << temp[j];
        }
        cout << endl;
    }
}

```