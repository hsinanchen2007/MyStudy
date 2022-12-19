### 解题思路
先往剩下数字大的那里放1

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ans;
        vector<int> up, down;
        for(int i = 0 ; i < colsum.size() ; ++i)
        {
            if(colsum[i] <= 0)
            {
                up.push_back(0);
                down.push_back(0);
            }
            else
            {
                if(colsum[i] == 1)
                {
                    if(upper > lower)
                    {
                        upper -= 1;
                        up.push_back(1);
                        down.push_back(0);
                    }
                    else
                    {
                        lower -= 1;
                        down.push_back(1);
                        up.push_back(0);
                    }
                }
                else
                {
                    upper -= 1;
                    lower -= 1;
                    up.push_back(1);
                    down.push_back(1);
                }
            }
        }
        if(upper == 0 && lower == 0)
        {
            ans.push_back(up);
            ans.push_back(down);
        }
        return ans;
    }
};
```