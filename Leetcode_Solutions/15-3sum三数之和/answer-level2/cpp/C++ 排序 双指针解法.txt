### 解题思路
看了大佬解法后仿写的双指针（vector<int>::iterator遍历vector<int>）
只能说有了双指针的内涵，但的确不算完美的答案（主要是内存消耗过大，仅击败了5.84%用户）

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        auto intNow = nums.begin();
        if(nums.size() < 2)
            return result;
        for (; intNow < nums.end() - 2; ++intNow)
        {
            auto lo = intNow + 1, hi = nums.end() - 1;
            if(*intNow > 0)
                break;
            int nagi = -*intNow;
            while(lo < hi)
            {
                if(*lo + *hi < nagi)
                    ++lo;
                else if(*lo + *hi > nagi)
                    --hi;
                else
                {
                    result.push_back({*intNow, *lo, *hi});
                    //去重
                    while(lo < hi && *(lo + 1) == *lo)
                        ++lo;
                    while(lo < hi && *(hi - 1) == *hi)
                        --hi;
                    ++lo; --hi;
                }
            }
            //去重
            while(intNow < nums.end() - 2 && *(intNow + 1) == *intNow)
                ++intNow;

        }
        return result;
	} 
};
```