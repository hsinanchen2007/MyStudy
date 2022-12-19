### 解题思路
使用priority_queue<int>  大顶堆


priority_queue<int,vector<inr>,greater<int>>  小顶堆

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> temp;
        for(int i = 0;i<nums.size();i++){
            temp.push(nums[i]);
        }
        int res;
        while(k){
            res = temp.top();
            temp.pop();
            k--;
        }
        return res;
    }
};
```