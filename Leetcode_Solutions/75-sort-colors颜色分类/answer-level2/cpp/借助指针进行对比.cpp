### 解题思路
方法1：题目中已经做了提示了，抛开交换排序的限制，从结果入手，依次是若干0，若干1，若干2，则遍历依次统计计数后重写数组。
方法2：借助3个指针进行处理：p0指向0的最右端，p2指向2的最左端，pCur从数组索引0开始遍历，直到pCur == p2。其中，由于每次和p2交换后，当前值并未遍历过，因此pCur不向后移动继续进行比较。

### 代码

```cpp
class Solution {
public:

    int Swap(vector<int>& nums, int lIdx, int rIdx)
    {
        if (lIdx < 0 || lIdx >= nums.size())
        {
            return -1;
        }

        if (rIdx < 0 || rIdx >= nums.size())
        {
            return -1;
        }

        if (lIdx == rIdx || nums[lIdx] == nums[rIdx])
        {
            return -1;
        }

        int tmp = nums[lIdx];
        nums[lIdx] = nums[rIdx];
        nums[rIdx] = tmp;
        return 0;
    }

    void sortColors(vector<int>& nums) 
    {
        int p0 = 0;
        int pCur = 0;
        int p2 = nums.size() - 1;

        while (pCur <= p2)
        {
            if (nums[pCur] == 0)
            {
                Swap(nums, p0, pCur);
                p0++;
                pCur++;
            }
            else if (nums[pCur] == 2)
            {
                Swap(nums, p2, pCur);
                p2--;
            }
            else
            {
                pCur++;
            }
        }
    }
};
```