### 解题思路
第一步： 实时更新数字最大的下标
第二步： 实时判断当前数字最大的小标是否在滑动窗口内部 ，i 始终为滑动窗口的头
第三步： 压入下标
第四步： 当滑动窗口的元素满足要求，即可压入元素

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;       //存放结果的vector
        deque<int>temp;          //记录最大数字小标的双向队列
        int length=nums.size();
        for(int i=0;i<length;i++)
        {
            while(!temp.empty()&&nums[i]>nums[temp.back()])
                temp.pop_back();
            while(!temp.empty()&&i-k+1>temp.front())
                temp.pop_front();
              temp.push_back(i);
            if(i-k+1>=0)
               result.push_back(nums[temp.front()]) ;
        }
        return result;
    }
};
```