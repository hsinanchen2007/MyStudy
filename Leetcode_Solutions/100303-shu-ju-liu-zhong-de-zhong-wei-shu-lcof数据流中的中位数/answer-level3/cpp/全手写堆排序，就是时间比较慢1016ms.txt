### 解题思路
此处撰写解题思路

### 代码

```cpp
class MedianFinder {
public:
    vector<int> maxHeap;
    vector<int> minHeap;

    MedianFinder() {

    }


    // flag 为 true 构造 最大堆，false构造最小堆
    void buildHeap(vector<int>& nums, int len, int index, bool flag) {
        int left = 2*index+1;
        if (left >= len) return;
        int right = 2*index+2;
        int mini = index, maxi = index;
        if(flag){
            if(left<len && nums[left]>nums[maxi]) maxi = left;
            if(right<len && nums[right]>nums[maxi]) maxi = right;
            if(maxi != index) {
                swap(nums[maxi], nums[index]);
                buildHeap(nums, len, maxi, flag);
            }          
        }else{
            if(left<len && nums[left]<nums[mini]) mini = left;
            if(right<len && nums[right]<nums[mini]) mini = right;
            if(mini != index) {
                swap(nums[mini], nums[index]);
                buildHeap(nums, len, mini, flag);
            }   
        }
    }

    // 将 num 添加到 heap 中，flag 为 true 表示最大堆
    void push_heap(int num, vector<int>& heap, bool flag){
        heap.push_back(num);
        // 自下而上调整堆
        for(int k=heap.size()/2-1; k>=0; --k )
            buildHeap(heap, heap.size(), k, flag);
    }

    // 弹出堆顶，flag 为 true 表示最大堆
    void pop_heap(vector<int>& heap, bool flag){
        swap(heap[0], heap[heap.size()-1]);
        heap.pop_back();        
        buildHeap(heap, heap.size(), 0, flag);
    }

    
    void addNum(int num) {
        if(maxHeap.empty() || num<maxHeap[0]) push_heap(num, maxHeap, true);
        else push_heap(num, minHeap, false);

        while (maxHeap.size() > (1+minHeap.size()))
        {
            push_heap(maxHeap[0], minHeap, false);
            pop_heap(maxHeap, true);
        }
        
        while (maxHeap.size() < minHeap.size())
        {
            push_heap(minHeap[0], maxHeap, true);
            pop_heap(minHeap, false);
        }
        
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) 
            return (maxHeap[0]+minHeap[0])/2.0;
        return maxHeap[0];
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```