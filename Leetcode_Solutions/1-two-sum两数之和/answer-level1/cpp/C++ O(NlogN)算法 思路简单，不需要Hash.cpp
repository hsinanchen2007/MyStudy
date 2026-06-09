### 解题思路
这题其实完全不需要用到hash表就能达到O(NlogN)的时间复杂度。
思路简单来讲，可以算是双指针，但其实用不到那么复杂。
首先将整个数组排序，因为必定是一个较小的数加上一个较大的数，因此只要逐个遍历较小的数，然后指向较大数的下标不断收缩即可。因为两者都是不可逆的，因此复杂度未为O(N)。
该代码没有优化空间，有一个原数组和一个备份数组，因此空间复杂度为O(N)。
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 备份原数组
        vector<int> tmp;
        for(int i = 0; i < nums.size(); i ++)
            tmp.push_back(nums[i]);
        // 对原数组进行排序
        sort(nums.begin(), nums.end());
        vector<int> res;
        // 头尾双向遍历
        int st = 0;
        int en = nums.size() - 1;
        while(st < en)
        {
            while(nums[en] + nums[st] > target && en > st) en --;
            if(en == st) break;
            if(nums[en] + nums[st] == target)
            {
                res.push_back(nums[st]);
                res.push_back(nums[en]);
            }
            st ++;
        }
        int las = -1;
        // 将输出转化回原数组中的位置，注意避免输入[3,3]这样的情况产生bug
        for(int i = 0; i < res.size(); i ++)
        {
            for(int k = 0; k < tmp.size(); k ++)
                if(tmp[k] == res[i] && k != las)
                {
                    res[i] = k;
                    las = k;
                    break;
                }
        }
        return res;
    }
};
```