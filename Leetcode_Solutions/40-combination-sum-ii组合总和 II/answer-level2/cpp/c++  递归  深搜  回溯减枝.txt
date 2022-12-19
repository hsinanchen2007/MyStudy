### 解题思路
利用深搜不断枚举的过程，是典型的递归回溯算法，耗时会很长，所以还需要减枝操作。
此题情形较简单，就两种：
    - 一是不加当前数字，继续递归；
    - 二是加上当前数字，继续递归。
思路举例： 若candidates = [1,1,2], target = 2, 则过程为：

![QQ图片20200323221032.png](https://pic.leetcode-cn.com/73da685e6ee35aa362321afcabfb8e5e03270de4f41262d5ad0e2b0d336e0f1f-QQ%E5%9B%BE%E7%89%8720200323221032.png)

最后的结果是用set存的，所以不会有重复。


### 代码

```cpp
class Solution {
public:
    set<vector<int>> sv;
    vector<int> v;
    vector<int> can;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        can = candidates;
        backtrack(0, target);
        vector<vector<int>> res(sv.begin(), sv.end());
        return res;
    }
    void backtrack(int i, int n) {
        if(n==0) {
            sv.insert(v);
            return ;
        }
        if(i < can.size()) {
            //情形一：不加can[i], 继续递归
            backtrack(i+1, n);
            //情形二： 加can[i],继续递归
            if(n-can[i] >= 0) {
                v.push_back(can[i]);
                backtrack(i+1, n-can[i]);
                v.pop_back();
            }
        }
          
    }

};
```