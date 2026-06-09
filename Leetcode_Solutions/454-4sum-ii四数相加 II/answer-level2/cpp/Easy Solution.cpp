### 解题思路
执行用时 :624 ms, 在所有 C++ 提交中击败了11.66% 的用户
内存消耗 :73.8 MB, 在所有 C++ 提交中击败了5.72%的用户

### 代码

```cpp

class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        if (!A.size() && !B.size() && !C.size() && !D.size())
            return 0;

        auto abMap = getSumMap(A, B);
        auto cdMap = getSumMap(C, D);

        int ret = 0;
        for (auto &el : abMap)
        {
            ret += cdMap[-el.first] * el.second;
        }
        return ret;
    }

private:
    unordered_map<int, size_t> getSumMap(vector<int> &A, vector<int> &B)
    {
        unordered_map<int, size_t> ret;
        for (auto &i : A)
        {
            for (auto &j : B)
            {
                ret[i + j]++;
            }
        }
        return ret;
    }
};
```