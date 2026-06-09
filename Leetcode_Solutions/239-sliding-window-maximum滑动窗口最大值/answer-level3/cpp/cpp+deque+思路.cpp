### 解题思路
思考：滑动窗口，需要输出窗口中的最大值，第一反应大顶堆，每次进来一个新元素，要把之前的元素踢掉一个，需要记录元素下标。第二种方法，用队列：向右边移动的时候，进来一个新的，就把最左边的去掉（从左边出去），在框内排序找到最大的。同时发现，如果进来一个大的数，比左边框里的一些数大，那么这些小数永远都不可能是最大值，那么把这些小数直接扔掉（从右边出去）。所以得出结论：用双端队列。每进来一个新数，就要存一个最大值到res中。

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;//队列中存的是下标
        vector<int> res;
        if(nums.empty()){return res;}
        for(int i=0;i<nums.size();i++)
        {
            //如果队列的个数等于k了，那么就弹出顶部
            if(!dq.empty()&&dq.front()==i-k){
                dq.pop_front();}
            //进行比较，如果进来的元素大小比最大的，则把之前比它小的元素都去掉
            while(!dq.empty()&&nums[i]>nums[dq.back()]){
                dq.pop_back();}  
             //需要双端队列，一个是滑动窗口的自然滑动，从左边出队pop_front,一个是右边的数比左边的数都大,从右边出队，pop_back(),
            dq.push_back(i);
            //最大值永远是队列的front，即滑动窗口的最左边
            if(i-k+1>=0){
                res.push_back(nums[dq.front()]);
            }
        }
return res;


    }
};
```