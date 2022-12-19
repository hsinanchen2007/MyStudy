### 解题思路

Nothing.

### 代码

```cpp
class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &A)
    {
        long long sum = 0;
        for (int x : A)
        {
            sum += x;
        }

        if (sum % 3 != 0)
        {
            return false;
        }

        long long ans = sum / 3;

        long long ans_tmp = 0;
        int correct_time = 0;
        for (int x : A)
        {
            ans_tmp += x;
            if (ans_tmp == ans)
            {
                ans_tmp = 0;
                correct_time++;
            }
        }

        if ((correct_time == 3 && ans_tmp == 0) || (correct_time >3 && ans == 0))
        {
            return true;
        }
        return false;
    }
};
```