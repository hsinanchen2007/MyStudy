### 解题思路
此处撰写解题思路
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
8.5 MB
, 在所有 C++ 提交中击败了
85.32%
的用户
### 代码

```cpp
class Solution {
public:
vector<vector<int>> ans;
    void dps(int k, int n, vector<int> vec, int idx)
    {
        if (vec.size() == k)
        {
            if (0 == n) ans.push_back(vec);
            return;
        }

        for (int i = idx; i<=9; i++)
        {
            if (i>n) continue;
            
            vec.push_back(i);
            dps(k, n-i, vec, i+1);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vec;
        dps(k,n,vec,1);
        return ans;
    }
};
```