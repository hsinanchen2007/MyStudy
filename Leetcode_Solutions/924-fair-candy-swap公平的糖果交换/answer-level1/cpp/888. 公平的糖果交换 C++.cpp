### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {

        int sum_a = 0;
        int sum_b = 0;

        // unordered_set<int> s_b;
        // s_b.reserve(B.size() * 4);
        set<int> s_b;

        for(int i = 0; i < A.size(); ++i)
        {
            sum_a += A.at(i);
        }

        for(int i = 0; i < B.size(); ++i)
        {
            sum_b += B.at(i);
            s_b.insert(B.at(i));
        }

        int diff = (sum_a - sum_b) / 2;

        //找A[i]、B[j] 使得 A[i] - B[j] = diff  即从set B中找 A[i] - diff 是否存在
        for(int i = 0; i < A.size(); ++i)
        {
            if(s_b.find(A.at(i) - diff) != s_b.end())
            {
                return vector<int>{A.at(i), A.at(i) - diff};
            }
        }

        return vector<int>();
    }
};
```