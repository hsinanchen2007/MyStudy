multiset 用于最大值
queue    记录滑动窗口，之前是用记录滑动窗口前面的下标，然后发现multiset删除函数传入参数为int值的时候，会删除掉所以重复的元素。
所以就用队列来记录每次插入set元素的迭代器。这样内存上和时间上都增加了很大开销，看有没有大佬能改进下


![image.png](https://pic.leetcode-cn.com/6d089ab852b6e23e2dc5901d0f87a1200248f5b3cefb6b7fd5ecfb0f0bdc3de1-image.png)

```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        
        multiset<int,greater<int>>                  tmpWindow;
        queue<multiset<int,greater<int>>::iterator> moveWindow;
        int i = 0;
        for(; i < nums.size(); i++)
        {
            auto it = tmpWindow.insert(nums[i]);
            moveWindow.push(it);
            if(i < k-1)continue;
            ret.push_back(*(tmpWindow.begin()));
            tmpWindow.erase(moveWindow.front());
            moveWindow.pop();
        }
        
        return ret;
    }
};
```