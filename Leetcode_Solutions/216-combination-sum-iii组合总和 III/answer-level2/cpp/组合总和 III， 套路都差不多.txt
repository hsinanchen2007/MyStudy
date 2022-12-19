### 解题思路
分析题目 
“相加之和” -> 在下一次层寻找 target - n , n 为本层数值；
“不存在重复的数字” -> 说明 dfs 中存在 start 参数；
“解集不能包含重复的组合” -> 输入参数需要预先排序， 但是此题是直接使用 1-9 数字的， 所以本身就是有序的， 剩下的基本就是套路了。
如果做过 组合总和 和 组合总和 II 还有 全排列 等相关题目， 此题其实应该属于非常常规的题目。
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        __combinationSum3(k, n, temp, 1);
        return res;
    }
private:
    void __combinationSum3(int k, int target, vector<int> temp, int start) {
        if(target > 0 && temp.size() <= k){
            for(int i = start; i < 10; i++){
                if(target == i && temp.size() == k - 1){
                    temp.push_back(i);
                    res.push_back(temp);
                }else{
                    temp.push_back(i);
                    __combinationSum3(k, target - i, temp, i + 1);
                    temp.pop_back();
                }
            }
        }
    }
};
```