
```cpp
/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int currMin = 0;
        int j = 0;
        for (int i = 0; i < houses.size(); i++)
        {
            while (j < heaters.size() && heaters[j] < houses[i])
            {
                j++;
            }
            if (j == 0)
            {
                int temp = heaters[j] - houses[i];
                currMin = max(currMin, temp);
            }
            else if (j < heaters.size())
            {
                int temp1 = houses[i] - heaters[j - 1];
                int temp2 = heaters[j] - houses[i];
                currMin = max(currMin, min(temp1, temp2));
            }
            else if (j == heaters.size())
            {
                int temp = abs(houses[i] - heaters[j - 1]);
                currMin = max(currMin, temp);
            }
        }
        return currMin;
    }
};
// @lc code=end

```
