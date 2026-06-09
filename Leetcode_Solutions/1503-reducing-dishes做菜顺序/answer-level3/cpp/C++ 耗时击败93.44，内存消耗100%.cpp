### 解题思路
先排序，然后从后往前计算当前值与后面所有值之和的大小，大于0则做这道菜，否则结束返回。

### 代码

```cpp
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int ret_val = 0;
        int satis_len = satisfaction.size();
        int num_sum = 0, sum = 0;
        sort(satisfaction.begin(), satisfaction.end());
        for(int i = satis_len -1; i >= 0; i--)
        {
            if(satisfaction[i] >= 0)
            {
                sum += satisfaction[i];
                num_sum +=sum;
            }
            else
            {
                if(satisfaction[i] + sum > 0)
                {
                    sum += satisfaction[i];
                    num_sum +=sum;
                }
            }
        }
        return num_sum;
    }
};
```