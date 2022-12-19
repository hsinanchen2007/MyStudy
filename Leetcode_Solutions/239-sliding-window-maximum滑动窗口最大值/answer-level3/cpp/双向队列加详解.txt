前面好多人都讲了双向队列，我这里根据大佬们的解法，总结几点如下
我们通过构建双向队列记录索引并进行如下的操作：
我们将窗口逐渐地向右移。
1.当队列不空且当前队头索引不在窗口内时，pop_front();
2.当队列不空且队尾索引对应的值小于当前值时，pop_back();
3.将当前地索引插入队尾。
4.返回队首元素为此时窗口内地最大值地索引
几点解释：
1.为什么上面地第二点可以删掉队尾地元素？
因为如果后来的索引对应的元素会在较后的时间内滑出窗口，所以比现在进来的元素小的就不可能再成为最大值。
2.为什么检查划出窗口元素的元素只检查队首？
因为队列中的元素按时间先后排序
3.为什么时间复杂度为O(N)？
因为对于每一个索引，他最多进入队列一次，出队列一次。
```
class Solution {
public:
    //双向队列
    deque<int> dep;
    void clean_queue(int idx,int i,vector<int>& nums){
        if(!dep.empty()&&idx==dep.front())dep.pop_front();
        while(!dep.empty()&&nums[dep.back()]<nums[i])dep.pop_back();
        dep.push_back(i);
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for(int i=0;i<k;i++){
            clean_queue(i-k,i,nums);
        }
        res.push_back(nums[dep.front()]);
        for(int i=k;i<nums.size();i++){
            clean_queue(i-k,i,nums);
            res.push_back(nums[dep.front()]);
        }
        return res;
    }
};
```

