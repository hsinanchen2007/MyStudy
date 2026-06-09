### 解题思路
joshua分享：必须保证队列保存的元素是当前扫描过，并且按照递减的顺序存放，其中，队首元素是当前的最大值

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        // 排除边界情况

        if(k > nums.size()) return ans;

        // 必须保证队列保存的元素是当前扫描过， 并且按照递减的顺序存放
        // 其中，队首元素是当前的最大值
        // 首先扫描前 k 个数据进行入队列操作
        for(int i = 0; i < k; i++) {
            while(!q.empty() && nums[i] > q.back()) q.pop_back();
            q.push_back(nums[i]);
        }
        // 加入第一个满足要求的元素
        ans.push_back(q.front());
        // 从第 k+1 个元素开始扫描
        for(int i = k; i < nums.size(); i++) {
            // i-k 是马上要滑出队列的元素，所以要进行判断：
            // 当前队首的元素值是否等于要滑出的元素值，如果是就要删除队首元素
            if(nums[i-k] == q.front()) {
                q.pop_front();
            }
            // 当前的元素加入队列，必须要保证：
            // 1. 最大元素放到队首;
            // 2. 队列元素按照递减的方式放进去;
            while(!q.empty() && nums[i] > q.back()) q.pop_back();
            q.push_back(nums[i]);
            // 当前的队列最大值（即：队首元素）存入结果
            ans.push_back(q.front());
        }
        return ans;
    }
};
```