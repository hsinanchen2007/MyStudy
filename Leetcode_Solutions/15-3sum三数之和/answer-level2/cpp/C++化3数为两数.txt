### 解题思路
本题在我一次笔试题中出现过，那个时候的想法很简单。直接排序暴力解法
所以没过。今天再次遇到了此题，便重新理了一下（借鉴别人~~）思路。
之前写的都没有进行排除重复元素处理，在这里我们需要两次排除重复元素。
1.进入的时候，我们要判断以及排好序的同时，数组不能有重复的数字进行首位指针判断
2.找到符合条件时。我们应该加两次判断进行排除重复元素。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //借鉴了一下大神的思路，首先我们如果使用暴力解法那么时间复杂度就是O(N^3)
        //我们可以借鉴一下两数之和的思路可以把题目化成a+b= -c，并且要排除重复的子数组答案
        vector<vector<int>> res;
        if(nums.size() <= 2) return res;
        int len = nums.size();
        //首先我们需要对数组进行排序然后使用首尾指针来进行。
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 2; i++)
        {
            //以nums[i]作为参考。双指针来作为a、b
            //这个地方要去掉重复的结果,i = 0时不需要判断
            if(i > 0 && nums[i] != nums[i - 1]|| i == 0)
            {
                int beg = i + 1;
                int end = len - 1;
                while(beg < end)
                {
                    if(nums[beg] + nums[end] == -nums[i])
                    {
                        //在此处还要进行排除重复,且要排除i与beg相等情况
                        if(nums[beg] != nums[beg - 1] || beg == i + 1)
                        {
                            //vector<int>tmp{nums[i], nums[beg], nums[end]};
                            res.push_back({nums[i], nums[beg], nums[end]});
                        }
                        beg++;
                        end--;
                    }
                    else if(nums[beg] + nums[end] > -nums[i])
                    {
                        end--;
                    }
                    else
                    {
                        beg++;
                    }
                }
            }
        }
        return res;
    }
};
```