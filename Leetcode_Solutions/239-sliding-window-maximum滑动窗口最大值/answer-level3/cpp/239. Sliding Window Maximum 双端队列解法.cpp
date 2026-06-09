### 解题思路
可以利用一个双端队列来进行操作. Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
首先初始化一个窗口 包含[1, 3, -1]这三个元素. 指针从头开始遍历, 首先将1压入双端队列, 然后将下一个数与队列尾部的数比较, 如果此数大于队尾数, 则将队列中的数弹出, 继续比较, 直到不满足大小关系或者队列为空, 再将此数压入, 每处理完成一个窗口, 队首的数都是此窗口最大的数. 直接在队首取数即可. 需要注意的时, 需要单独处理移出滑动窗口的数. 

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        int len = nums.size();
        vector<int> res;
        if(k == 1)
            return nums;
        for(int i = 0; i < len; i++){
            if(deq.empty()){
                deq.push_back(nums[i]);
                continue;
            }
            if(i >= k && nums[i - k] == deq.front()){
                deq.pop_front();
            }
            while(!deq.empty() && nums[i] > deq.back()){
                deq.pop_back();
            }
            deq.push_back(nums[i]);
            if(i >= k - 1){
                res.insert(res.end(), deq.front());
            }
        }
        return res;
    }
};
```