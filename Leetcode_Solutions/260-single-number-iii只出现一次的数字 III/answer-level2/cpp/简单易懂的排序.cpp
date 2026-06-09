高赞中有提过排序，但是太复杂，实际排序也可以很简单。
基本原理如下：
1. 从前往后遍历，若出现两次，则为相同元素，索引加2
2. 若出现一次（前后不等），则为所需要的数，存入vector，索引加1
3. 若没到尾后位置，说明最后一个元素为出现一次的数

例如：
    0 1 2 2
    ^-^-^----^
    0 2 2 3
    ^-^----^


```
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int i = 0;
        for ( ; i < nums.size() - 1; ) {
            if (nums[i] == nums[i + 1]) {
                i += 2;
            } else {
                res.push_back(nums[i]);
                i += 1;
            }
        }
        if (i < nums.size()) {
            res.push_back(nums[i]);
        }
        return res;        
    }
};
```
