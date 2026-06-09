### 解题思路
这题让我想起一个题目，找到数组中出现次数超过一半的数；用的快排的partition函数的思路;
具体步骤是这样的：
1. 在vector中取一个数，下标设为idx，将所有小于**等于**它的数放在它的左侧，则右侧都是大于它的数；
2. 0～idx的数，一共idx+1个数都是小于等于nums[idx]的;如果这些数的数量=3n，则说明左侧没有我们要找的数，将start设定为idx+1;
3. 如果这些数的数量=3n+1;则我们要找的数在左侧,将end设定为idx;
4. 这里会有一种特殊情况，就是形如[2,2,2,3]这样的；patition一次后依旧是[2,2,2,3]，导致死循环
5. 所以我们需要记录前一次partition返回的index,与本次比较，如果相同，则需要重新partition且选取的位置也要和之前不同；

### 代码

```cpp
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int index = 0;
        int start = 0;
        int offset = 0;
        int oldIndex = -1;
        int end = nums.size() - 1;
        do
        {
            oldIndex = index;
            index = partition(nums, start, end, offset);
            if (index == oldIndex)
            {
                ++offset;
            }
            //index之前有几个数 >=nums[index]
            if (index % 3 == 2)
            {
                start = index + 1;
            }
            else if (index % 3 == 0)
            {
                end = index;
            }

        } while (start != end);

        // return index;
        return nums[start];
    }
    int partition(vector<int> &nums, int start, int end, int offset = 0)
    {
        int randIdx = start + (offset % (end - start + 1));
        // int randIdx = (start + end) / 2;
        std::swap(nums[randIdx], nums[end]);
        int nextSmall = start;
        for (int i = start; i < end; i++)
        {
            if (nums[i] <= nums[end])
            {
                if (i != nextSmall)
                {
                    swap(nums[i], nums[nextSmall]);
                }
                ++nextSmall;
            }
        }
        swap(nums[nextSmall], nums[end]);
        return nextSmall;
    }
};
```