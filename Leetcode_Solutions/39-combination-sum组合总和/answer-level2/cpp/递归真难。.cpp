### 解题思路
递归真难啊。 写了1个半小时。**** 
递归函数中先把最终的结果列出来。然后再去想应该如何回到上一步。这里是temp.pop_back();把原来压进去的弹出来。

若没有到最终的情况应该temp.push_back(candidates[i]);把当前的数压进去。然后进行下一次递归。
注意这儿通过index使res不会压入重复的步骤。

### 代码

```cpp
class Solution {
public:
    // 执行用时 :4 ms, 在所有 C++ 提交中击败了97.98% 的用户
    // 内存消耗 :7.5 MB, 在所有 C++ 提交中击败了100.00%的用户
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size()==0) return res;
        vector<int> temp;
        combinationSumCore(candidates, target, temp, 0, res);//递归调用,这里的0表示从candidates[0]开始查询。
        return res;
    }

    void combinationSumCore(vector<int>& candidates, int target, vector<int>& temp, int index, vector<vector<int>>& res){
        if(target==0){
            res.push_back(temp);//若target==0了，就插入temp;
        }
        else{
            for(int i = index;i<candidates.size();++i){//这里从index开始查询，避免重复查询。
                if(target-candidates[i]>=0){
                    temp.push_back(candidates[i]);//先把数压进去。
                    combinationSumCore(candidates, target-candidates[i], temp, i, res);//index=i，下次就不会重复查i了。
                    temp.pop_back();//若不相等就弹出来。
                }
            }
        }
    }
};
```