### 解题思路
本题关键是如何找到线性解放，我们可以依次遍历数组，找到当前最大值，比如k=2，遍历nums[0],nums[1]可以找到一个窗口为k=2的最大值，那么考虑区间[1, 2]时，分两种情况：

1. 前一个取间最大值不是nums[0]，也就是不是i-k,i为当前元素（即将添加进来的元素)， 那么只要nums[i]大于前一个区间最大值即可
2. 前一个区间的最大值是i-k，那么我们只能比较当前元素与前一个区间的次大值

考虑单调栈，这里我们维护一个单调递减的栈，栈顶是区间疑似最大值，只有栈顶元素在区间内才是

为啥有while还是线性： 如果给定数组单调递增，那么只有第一次while要循环i-1次，i为当前考虑位置，以后每次单调栈都只有一个元素

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> max_stack;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            while(!max_stack.empty() && nums[i] >= nums[max_stack.back()]) {//维护单调栈
                max_stack.pop_back();
            }
            max_stack.push_back(i);//可以入栈了
            if(i-k == max_stack.front())//当前最大值是否在区间内
                max_stack.pop_front();
            if(i+1-k>=0)//是否已经达到了窗口，比如第一个窗口k=3, 那么i+1-k = 0，即i==2的时候已经有第一个区间了
                res.push_back(nums[max_stack.front()]);
        }

        return res;
    }
};
```