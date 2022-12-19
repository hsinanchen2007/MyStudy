### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> small_heap;  //维护一个最小堆
        for(int i = 0;i < nums.size(); i++)
        {
            if(k>0)
            {
                small_heap.push(nums[i]);
                k--;
            }
            else
            {
                if(nums[i] > small_heap.top())
                {
                    small_heap.pop();  //弹出顶部最小元素
                    small_heap.push(nums[i]);
                }
            }
        }
        return small_heap.top();
    }
};
```