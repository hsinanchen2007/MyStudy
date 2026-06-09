### 解题思路
此题的解可以理解为一颗树的结构， 树的每个节点下都挂着 candidates 中所有的数值的节点， 树的深度就是 candidates 元素的个数， 求解过程就是遍历这棵树的每一个路径， 并计算路径和
因为每个位置的元素都可以重复选择， 所以可以理解为树的下一层挂有和本节点相同的兄弟节点。
并且要求解不重复， 所以从左到右， 每组兄弟节点的数量逐渐减少， 这里如果不好理解可以想象一下把所有的解分个类， 必然可以分为以 [candidates[0],... ,candidates[candidates.size()-1]] 开头的 candidates.size() 组的解， 从左到右的分支实际上就是按照这个分类进行求解的。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        __combinationSum1(candidates, target, temp, 0， 0);
        // __combinationSum2(candidates, target, temp, 0);
        return res;
    }
private:
    // 遍历路径求并和
    // temp: 存放可能为解的结果
    // start： 开始位置
    // temp_sum: vector<int> temp 现有元素的和， 用这个参数可以简化计算过程
    void __combinationSum1(vector<int>& candidates, int target, vector<int> temp, int temp_sum, int start){
        if(temp_sum == target){
            res.push_back(temp);
        }else if(temp_sum > target){
            return;
        }else{
            for(int i = start; i < candidates.size(); i++){
                temp.push_back(candidates[i]);
                __combinationSum(candidates, target, temp, temp_sum + candidates[i], i);
                temp.pop_back(); // pop 是为了回溯， 也可以理解为不让此次循环 push 的数值带入下一个分支
            }
        }
    }
    // 在下一层寻找需要的元素数值
    // temp: 存放可能为解的结果
    // start： 开始位置
    // target: 当前与和相差的数值
    void __combinationSum2(vector<int>& candidates, int target, vector<int> temp, int start){
        if(target == 0){
            res.push_back(temp); 
        }else{
            for(int i = start; i < candidates.size(); i++){
                if(target >= candidates[i]){
                    temp.push_back(candidates[i]);
                    __combinationSum(candidates, target - candidates[i], temp, i);
                    temp.pop_back();
                }

            }
        }
    }
};
```