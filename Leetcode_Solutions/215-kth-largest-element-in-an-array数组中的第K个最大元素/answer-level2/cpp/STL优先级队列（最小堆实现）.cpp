```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int> > small_heap;  //最小堆构造   
        int n=nums.size();
        for(int j=0;j<n;j++){
            if(small_heap.size()<k){
                small_heap.push(nums[j]);
            }
            else if(small_heap.top()<nums[j]){
                small_heap.pop();
                small_heap.push(nums[j]);
            }
        }
        return small_heap.top();
    }
};
```
