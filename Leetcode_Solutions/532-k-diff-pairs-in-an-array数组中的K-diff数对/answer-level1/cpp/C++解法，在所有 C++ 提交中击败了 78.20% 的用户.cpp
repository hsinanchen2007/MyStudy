### 解题思路
采用双指针，在不同的条件下，移动不同的指针
### 代码

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int num = 0;
        int tmp = 0;
        int tx = 0;
        sort(nums.begin(), nums.end());
        vector<int>::iterator it1 = nums.begin();
        vector<int>::iterator it2 = it1 + 1;
        while (it1 != nums.end() && it2 != nums.end())
        {
            if (*it2 - *it1 < k)
            {
                it2++;
            }
            else if (*it2 - *it1 == k && (*it2 != tmp || tx == 0))
            {
                num++;
                tmp = *it2;
                it2++;
                tx++;
            }
            else if (*it2 - *it1 == k && *it2 == tmp)
            {
                it2++;
            }
            else
            {
                it1++;
                if (it1 == it2)
                {
                    it2++;
                }
            }
        }
        return num;
    }
};
```