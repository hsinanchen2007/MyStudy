```
class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap;
        for(int i=0;i<nums.size();i++){
            if(heap.size()<k) {
                heap.push_back(nums[i]); 
                continue;
            }else{
             make_heap(heap.begin(),heap.end(),greater<int>());//创建小根堆
            if(nums[i]>heap[0])//若比根节点大则插入
            {
                heap.push_back(nums[i]);
                push_heap(heap.begin(),heap.end(),greater<int>());
            }
            if(heap.size()>k)
            {
              pop_heap(heap.begin(),heap.end(),greater<int>());
                heap.pop_back();
            }

        }
        }
        make_heap(heap.begin(),heap.end(),greater<int>());//创建小根堆
        return heap[0];
    }
};
```
