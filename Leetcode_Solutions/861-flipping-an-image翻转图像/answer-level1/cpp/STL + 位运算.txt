### 解题思路
暴力STL +位运算

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto &v: A)
        {
            reverse(v.begin(),v.end());          //直接用标准模板库的reverse反转
            for(int &i : v)
            {
                i = i^1;              //位运算  https://www.zhihu.com/question/38206659
            }
        }
        return A;
    }
};
```