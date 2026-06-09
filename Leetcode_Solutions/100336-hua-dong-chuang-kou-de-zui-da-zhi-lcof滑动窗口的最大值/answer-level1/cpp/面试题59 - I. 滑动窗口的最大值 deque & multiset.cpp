```cpp

// 1. deque 双端队列dq保存索引 O(n)
//
// I 确保 dq 的 front 始终是当前窗口最大值对应的索引
// II 为了确保I，每当窗口滑动，出现新索引时，需要不断从 dq 中 pop_back 掉值比当前索引对应值小的索引
// III 当当前的索引与dq的front保存的索引相差大于k时，应该pop_front掉头
//
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty() || k == 0 || nums.size() < k)
            return res;
        
        deque<int> dq;
        for (int i = 0; i <= k - 1; i ++) {
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        
        for (int i = k ; i <= nums.size() -1; i ++) {
            res.push_back(nums[dq.front()]);
            while(!dq.empty() && nums[dq.back()] < nums[i])  //1.
                dq.pop_back();
            if (!dq.empty() && dq.front() < i - k + 1) //2.
                dq.pop_front();
            dq.push_back(i);  
            // push当前索引前需确认 
            // 1.pop_back掉了所有值比当前值小的索引
            // 2.dq中的front还没有掉出窗口范围
        }
        res.push_back(nums[dq.front()]);   // 上面循环完了后遗漏了一次
                         
        return res;

    }
};



// // 2. multiset O(nlogn)
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> res;
//         multiset<int> set; //默认从小到大，获取最大元素用rbegin
//         for (int i = 0; i < k - 1; i++) 
//             set.insert(nums[i]);

//         for(int i = k - 1; i < nums.size(); i++) {
//             set.insert(nums[i]);
//             res.push_back(*set.rbegin());
//             // cout << nums[i-k+1] << endl;
//             // set.erase(set.find(nums[i-k+1]));   // 删除multiset中重复元素中的一个  
//             set.erase(nums[i-k+1]);
//             while (set.size() != k - 1)
//                 set.insert(nums[i-k+1]);    
//         }
//         return res;

        
//     }
// };
```