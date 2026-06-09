### 解题思路
哈希表统计每个数字出现的次数。
然后遍历数组，根据当前每个数组的值去哈希表找比他小的数的次数。

### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int map[101]={0};
        vector<int> res;

        //统计每个数字出现的次数
        for(int i=0;i < nums.size();++i)
        {
            map[nums[i]]++;
        }
        
        for(int i = 0;i < nums.size();++i)
        {
            int cnt = 0;
            for(int j = 0;j < nums[i];++j)//num[i]是当前数字
            {
                cnt += map[j];//统计map里面小于num[i]的次数
            }
            res.push_back(cnt);
        }
        return res;
    }
};
```