### 解题思路

执行用时 :8 ms, 在所有 C++ 提交中击败了30.36%的用户

一个一个向里加

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> rt;
        vector<int> tmp;
        rt.push_back(tmp);
        for(int num: nums){
            vector<vector<int>> rt_tmp;
            for(auto res: rt){
                res.push_back(num);
                rt_tmp.push_back(res);
            }
            for(auto res: rt_tmp){
                rt.push_back(res);
            }
        }
        return rt;
    }
};
```