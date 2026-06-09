### 解题思路
1、连续正数不大于(target/2+1)
2、双指针，j往右移动，直到sum大于等于target
3、sum=target，则正数范围[i,j]。结果放入数组后，j往右移动一位。
4、sum>target,则i往右移动。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> vec;
        if (target <= 2)
            return vec;
        int n = target / 2 + 1;
        int i = 1, j = 1;
        int sum = i;
        while (j <= n)
        {
            while (j <= n && sum < target)
            {
                j++;
                sum += j;
            }
            if (sum < target)
            {
                break;
            }
            if (sum == target && i < j)
            {
                vector<int> vec_t;
                for (int k = i; k <= j; k++)
                {
                    vec_t.push_back(k);
                }
                vec.push_back(vec_t);
                j++;
                sum += j;
            }
            else
            {
                while (i < j && sum > target)
                {
                    sum -= i;
                    i++;
                }
                if (i >= j)
                {
                    break;
                }
                if (sum == target && i < j)
                {
                    vector<int> vec_t;
                    for (int k = i; k <= j; k++)
                    {
                        vec_t.push_back(k);
                    }
                    vec.push_back(vec_t);
                    j++;
                    sum += j;
                }
            }
        }
        return vec;
    }
};
```