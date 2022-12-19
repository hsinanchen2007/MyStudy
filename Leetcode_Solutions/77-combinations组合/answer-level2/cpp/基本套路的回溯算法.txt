### 解题思路
 这种不考虑顺序得求所有解得回溯算法, 基本套路都是只向后看, 下一层从这一层后面得元素开始求解, 回溯算法的套路基本就那几种.

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        __combine(temp, n, k, 1);
        return res;
    }
private:
    // 树的每一层 [start, n] 遍历每一个元素, 放入 temp 中, 如果找到 k 个, 就算找到一组解
    void __combine(vector<int> temp, int n, int k, int start) {
        if(temp.size() == k){
            res.push_back(temp);
        }else{
            for(int i=start; i <= n; i++){
                temp.push_back(i);
                __combine(temp, n, k, i + 1);
                temp.pop_back();
            }
        }
    }
};
```