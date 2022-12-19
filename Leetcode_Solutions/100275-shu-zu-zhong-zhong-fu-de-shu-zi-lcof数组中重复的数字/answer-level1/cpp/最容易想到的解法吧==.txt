> 初始化一个大小为100000的vector,令给定数组中的元素值为下标，每遍历一个就+1，然后判断是否`>=2`,一旦满足要求就return当前元素.(要求返回任一个重复值即可)

```
class Solution 
{
public:
    int findRepeatNumber(vector<int>& nums) 
    {
        vector<int> vec(100000,0);
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            vec[*it]++;
            if (vec[*it] >= 2)
            {
                return *it;
            }
        }
        return -1;
    }
};
```
