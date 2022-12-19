```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>max_val;
        vector<int> max;
        if (nums.size() == 0)
            return max;
        if (k == 1)//长度为1，就是自身
            return nums;
        k--;//窗口还剩k-1个元素
        max_val.push_front(0);//队头放入第一个元素

        for(int i=1;i<nums.size();i++)//依次遍历
        {
            if(!max_val.empty()&&k+max_val.front()<i)//遍历的第i个元素下标位置超过窗口大小，要保持元素在窗口内
              max_val.pop_front();

            while(!max_val.empty()&&nums[max_val.back()]<=nums[i])//递减序列
              max_val.pop_back();
            
            max_val.push_back(i);//将当前最大值放入队尾
            if(i>=k)
              max.push_back(nums[max_val.front()]);
        }
        return max;
    }
};
```
