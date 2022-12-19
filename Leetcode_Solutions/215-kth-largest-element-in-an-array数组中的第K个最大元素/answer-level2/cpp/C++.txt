### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end(), std::greater<int>()); //从大到小排序
        return nums.at(k - 1);
    }

    //优先队列
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> queue(nums.begin(), nums.end());

        for(int i = 0; i < k - 1; ++i)
        {
            queue.pop();
        }

        return queue.top();
    }

    //BFPRT 算法 解TOP-K问题
};
```