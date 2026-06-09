### 解题思路
利用优先队列维护K—size的小顶堆

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int,vector<int>,greater<int> > Q;//最小堆
        for(int i = 0; i < nums.size(); i++) {
            if(Q.size() < k) {
                Q.push(nums[i]);
            } else if (nums[i]>Q.top()) {
                Q.pop();
                Q.push(nums[i]);
            }
        }
        return Q.top();	
    }
};
```