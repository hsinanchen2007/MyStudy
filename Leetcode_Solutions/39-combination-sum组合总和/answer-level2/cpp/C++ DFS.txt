解题思路：
DFS不用套固定模板，理解核心思路即可自行撸；
思考几个点：
1：搜索过程如何进行？
2：什么时候跳出去？避免死循环深递归
3：什么时候满足条件？怎么记录结果？记录结果需要中间的哪些东西？
4：如何往下一个结果递进？需要带什么状态给下一个结果？
5：初始状态是啥？
思考上述几个方面，dfs都能求解；至于中间态要保存什么？思考后可以自行添加，实现方式因人而异无固定；


c++才是生产力
读题，数字可以多次取；满足target则记录结果，过程中记录结果；
将遍历思考为一颗树，dfs搜索过程符合找target的过程； 注意要想办法记录中间态结果；
再次注意，要记录step，为啥？
2 3 5求target8，2 3 3和3 2 3, 3 3 2是同一组结果对吧？题目给的结果只有2 3 3这组，因此等价的元素不能算；
刚好dfs搜索的过程符合找数字的过程，因此要加step，否则会将三组结果都搜出来；

```
class Solution {
private:
    void dfs(vector<vector<int>> &res, vector<int> &cand, int step,
             int target, vector<int> &tmp, int sum)
    {
        if (sum > target)
            return;
        if (sum == target) {
            res.push_back(tmp);
            return;
        }
        
        for (int s = step; s < cand.size(); s++) {
            tmp.push_back(cand[s]);
            dfs(res, cand, s, target, tmp, sum + cand[s]);
            tmp.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        vector<int> tmp;
        dfs(res, candidates, 0, target, tmp, 0);

        return res;
    }
};
```
