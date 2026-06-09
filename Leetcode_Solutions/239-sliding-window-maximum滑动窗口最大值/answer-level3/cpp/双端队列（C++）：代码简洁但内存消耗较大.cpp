### 解题思路
在每次的滑动窗口中，对比数组中的**当前数字**与滑动窗口的**队尾数字**的大小：
（1）如果队尾数字小于当前数，则将队尾数字删除，然后将当前数字添加到队尾；
（2）否则，直接将当前数字添加到队尾。
这样可以保证**队首的数总是当前窗口中最大的数**，每次将其添加到vector中即可。
【注意】：
（1）需要考虑测试用例为**空数组**的情况；
（2）窗口每向右滑动一位，需要从双端队列window的队首删除一位。
### 代码

```cpp
class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if(k==0)  //测试用例中有空数组的特殊情况
        {
            return {};
        }
        deque<int>window;
        vector<int>max_num_set;
        for (int i=0;i<=nums.size()-k;i++)
        {
            if (!window.empty())  //滑动窗口后移一位，删除队列的第一个元素
            {
                window.pop_front();
            }
            for (int j=i;j!=i+k;j++)
            {
                while(!window.empty() && nums[j]>window.front())
                {
                    window.pop_back();
                }
                window.push_back(nums[j]);
            }
            max_num_set.push_back(window.front());
        }
        return max_num_set;
    }
};
```