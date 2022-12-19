### 代码

```cpp
class Solution {
public:
    vector<vector<int>> rs;
    void combinationSum2_(vector<int>& candidates,int start, vector<int>& res,int target){
        if (target < 0) return;
        
        if (target == 0) {
            rs.push_back(res);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target){
                //剪枝2 总和8  数组[1,2,7] 当candidates[i] = 7，而剩余的target = 8 - 1 - 2 = 5 < 7，  排好序了，后面的只会更大 此时无解
                return;
            }
            //剪枝1 例如 1,2,2,2,5 因为之前数组已经排过序了
            //比如第一个递归1 2 2
            //                层数
            //[1] 2 2 2 5     0
            //1 [2] 2 2 5     1
            //1 2 [2] 2 5     2  递归结束
            //当递归结束 res = [1,2,2] 返回第二层 target = 2 res = [1,2]
            //返回到 第二层  for循环继续  第二层 2 已经用过了，跳过
            //for循环结束 返回到第1层  target = 4 res = [1]
            if(i > start && candidates[i] == candidates[i-1]) continue;
            res.push_back(candidates[i]);
            combinationSum2_(candidates, i + 1,res, target - candidates[i]);
            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>res;
        //必须排序
        //1:方便去重
        //2:如果和超过了 target  不排序 不知道大小  加上的 还要减掉重新计算
        sort(candidates.begin(), candidates.end());
        combinationSum2_(candidates,0, res, target);
        return rs;
    }
};
```