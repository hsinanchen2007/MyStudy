### 解题思路
得到一个数nums[i],将双端队列deque从尾部开始把每个小于nums[i]的数去除。
一个窗口的最大值就是deque的头。
记得遍历nums时遇到nums[i-k]等于deque头的元素，要把deque的头去除掉，相当于一个最大值移出了窗口

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size() == 0)
        {
            return res;
        }
        if (k == 1)//长度为1，就是自身
        {
            return nums;
        }
        deque<int> maxque;
        maxque.push_back(nums[0]);
        int maxk = nums[0];
        for (int i = 1; i < k; i++)
        {
            if (i == nums.size())   //万一k比nums的个数还要大
            {
                res.push_back(maxk);
                return res;
            }
            if (maxk < nums[i])
            {
                maxk = nums[i];
            }
            while (!maxque.empty() && nums[i] > maxque.back())//从尾部开始把每个小于nums[i]的数去除。
            {
                maxque.pop_back();
            }
            maxque.push_back(nums[i]);
        }
        
        res.push_back(maxk);//第一个窗口的最大值

        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i - k] == maxque.front())//nums[i-k]移出窗口，如果队列头是nums[i-k]就要去除掉
            {
                maxque.pop_front();
            }
            while (!maxque.empty() && nums[i] > maxque.back())//从尾部开始把每个小于nums[i]的数去除。
            {
                maxque.pop_back();
            }
            maxque.push_back(nums[i]);
            res.push_back(maxque.front());
        }
        return res;
    }
};
```