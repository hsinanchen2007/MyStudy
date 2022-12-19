### 解题思路
关键点：
1、数组排序，这样可以减少重复检索次数；
2、在solution类中定义成员变量，或者使用引用传递，可以减少空间复杂度。

### 代码

```cpp
class Solution {
    vector<int> can;
    int tar;
    vector<vector<int>> res;
    vector<int> t;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->can=candidates;
        this->tar=target;
        dfs (0,0);
        return res;
    }
    void dfs(int a,int start){
        if (a==tar) res.push_back(t);
        else if (a<tar) {
            for (int i=start;i<can.size();i++){
                if ((a+can[i])<=tar) {
                    t.push_back(can[i]);
                    dfs(a+can[i],i);
                    t.pop_back();
                }
                else break;
            }
        }
    }
};
```