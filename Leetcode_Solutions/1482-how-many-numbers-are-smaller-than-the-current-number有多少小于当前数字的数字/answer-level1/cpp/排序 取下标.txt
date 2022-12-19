我的解法思路是用空间换时间，首先进行一次排序。根据下标自然就知道了小于元素的个数了。

```
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ret(0), sotr_num = nums;
        sort(sotr_num.begin(), sotr_num.end());
        for (int i = 0; i < nums.size(); i++) {
            vector<int>::iterator it = find(sotr_num.begin(), sotr_num.end(), nums[i]);
            int index = distance(sotr_num.begin(), it);
            ret.push_back(index);
        }
        return ret;
    }
};
```