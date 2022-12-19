### 解题思路
此处撰写解题思路
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
8.1 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
### 代码

```cpp
class Solution {
public:
vector<vector<int>> ans;
    int getsum(vector<int> & vec)
    {
        int tmp = 0;
        for (auto x: vec) tmp+=x;
        return tmp;
    }

    void dps(vector<int> & vec, int k, int n, int idx) 
    {
        if (vec.size() >= k)
        {
            if (vec.size() == k && getsum(vec) == n) ans.push_back(vec);
            return;
        }

        for (int i = idx; i <= 9; i++)
        {
            if (getsum(vec) >= n) continue;
            
            vec.push_back(i);
            dps(vec, k, n, i+1);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        if (k<0 || n<0) return ans;

        vector<int> vec;
        dps(vec, k, n, 1);
        return ans;
    }
};
```