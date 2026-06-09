### 解题思路
1.建立一个大小为k的最大堆
2.如果最大堆中元素个数小于k则元素入堆
3.如果新加入的元素与top相比较，大于top，则弹出top，将该元素入堆
4.最后top即为第k个数
### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int,std::vector<int>,std::greater<int> > max_queue;
        for(size_t i=0;i<nums.size();i++){
            if(max_queue.size() < k){
                max_queue.push(nums.at(i));
            }else{
                if(nums.at(i) > max_queue.top()){
                    max_queue.pop();
                    max_queue.push(nums.at(i));
                }
            }
        }
        return max_queue.top();
    }    
};
```