### 解题思路
小顶堆排序(最小优先队列)
### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //<数据类型，数组容器，排序规则>
        //greater从小到大，小得放到队顶 小顶
        //less从大到小，大得放到队顶 大顶
       priority_queue<int,vector<int>,greater<int>> q;
       for(auto it:nums){
           q.push(it);
           if(q.size()>k){
               q.pop();
           }
       }
        return q.top();
    }
};
