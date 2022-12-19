`剑指offer---P288-291`

>给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

1. 暴力法：扫描每个滑动窗口的所有数字并找出其中的最大值，时间复杂度O(nk)。
2.队列法：把滑动窗口的每一个值都存入队列queue。 一个滑动窗口可以看成一个队列，当窗口滑动时，窗口的第一个数字被删除，同时窗口末尾添加一个新的数字，符合队列先进先出的特性。由面试题9和30可知，可以用两个栈实现一个队列，用O(1)的时间得到队列的最大值，总的时间复杂度降到了O(n)。
3. 双端队列法：只把有可能成为滑动窗口最大值的数值存入双端队列deque。定义一个双端队列index，用来保存有可能成为滑动窗口最大值的数字的下标，在存入一个数字的下标之前，首先判断队列里已有数字是否小于待存入的数字。如果小于，那么这些数字已经不可能是滑动窗口的最大值，将他们依次从队尾删除。同时，如果队头的数字已经从窗口里滑出，那么滑出的数字也需要从队头删除。

```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len=nums.size();
        if(len<=0)return {};
        deque<int>index;
        vector<int>maxInWindows;
        for(int i=0;i<k;i++)
        {
            while(!index.empty() && nums[i]>=nums[index.back()])
                index.pop_back();
            index.push_back(i);
        }
        for(int i=k;i<len;i++)
        {
            maxInWindows.push_back(nums[index.front()]);
            while(!index.empty() && nums[i]>=nums[index.back()])
                index.pop_back();
            if(!index.empty() && index.front()<=(int)(i-k))
                index.pop_front();
            index.push_back(i);
        }
        maxInWindows.push_back(nums[index.front()]);
        return maxInWindows;
    }
};
```