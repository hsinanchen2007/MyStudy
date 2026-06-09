### 解题思路
用map先统计元素出现次数，最后从map中找出出现次数最多的元素

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> dict;
        for ( int i = 0; i< nums.size(); i++)
        {
            if (dict.count(nums[i]) > 0)
            {
                dict[nums[i]] += 1;
            }
            else{
                dict[nums[i]] = 1;
            }
        }

        int item;
        int times = 0;
        for (map<int, int>::iterator it = dict.begin(); it != dict.end(); it++)
        {
            if ( it->second > times )
            {
                item = it->first;
                times = it->second;
            }
        }
        return item;
    }
};
```