### 解题思路
1、暴力法  对n - k + 1个滑动窗口， 在每个窗口的k个值中选最大值  (n - k + 1) * k  时间复杂度O(n * k)

2、单调队列（双端队列） 时间复杂度O(n)

### 代码

```cpp
class Solution {
public:

    //1、暴力法 时间复杂度 O(N * K)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        if(nums.empty())
            return vector<int>();

        vector<int> v;
        v.reserve(nums.size() - k + 1);
        for(int i = 0; i < nums.size() - k + 1; ++i) //滑动窗口下标
        {
            v.push_back(select_max(nums, i, i + k - 1));
            // v.push_back(*max_element(nums.begin() + i, nums.begin() + i + k));
        }
        return v;
    }

    int select_max(vector<int>& nums, int begin, int end)
    {
        int max = nums.at(begin);

        for(int i = begin + 1; i <= end; ++i)
        {
            if(nums.at(i) > max)
            {
                max = nums.at(i);
            }
        }

        return max;
    }


    //2、单调队列（双端队列） 
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        //在数组非空时，k总是有效 可以不检验k
        if (nums.empty() 
        // || k < 1 || k > nums.size() 
        ) 
            return vector<int>();

        vector<int> res;
        res.reserve(nums.size() - k + 1); //滑动窗口个数

        list<int> max_queue;

        for (int i = 0; i < nums.size(); ++i)
        {
            while (!max_queue.empty() && nums.at(max_queue.back()) <= nums.at(i))
            {
                max_queue.pop_back();
            }

            max_queue.push_back(i);

            //判断队首是否过期
            if (max_queue.front() == i - k)
            {
                max_queue.pop_front();
            }

            if (i >= k - 1) //窗口出现
            {
                res.push_back(nums.at(max_queue.front()));
            }
        }

        return res;
    }
};
```