解决一个回溯问题，实际上就是一个决策树的遍历过程，因此按照回溯算法标准模板的思路来实现。

```
vector<vector<int>> m_Result;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        backTrack(1, n, k, ans);
        return m_Result;
    }

private:
    void backTrack(int start, int end, int k, vector<int>& ans){
        if (ans.size() == k){           // 结束条件
            m_Result.push_back(ans);    // 添加决策结果
            return ;
        }

        for (int i = start; i <=end ; ++i) {
            ans.push_back(i);                            //  选择i
            backTrack(i+1, end, k, ans);        //  进入下一层决策
            ans.pop_back();                              //  取消选择i
        }

    }

    vector<vector<int>> m_Result;
};
```
