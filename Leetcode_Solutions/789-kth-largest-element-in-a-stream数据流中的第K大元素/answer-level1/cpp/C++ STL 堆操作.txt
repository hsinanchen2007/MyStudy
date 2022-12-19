#### 重点是维护一个k元素的小顶堆，堆里是过去数据流中最大的k个元素，堆顶是其中最小的元素，当val大于堆顶元素时出堆，再將val入堆
#### 其他要考虑的问题是，当数据流中没有k个元素时的操作，初始化多于k个元素的操作
```
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        if(nums.size()<k) 
        {
            heap.assign(nums.begin(), nums.end());
        }
        else
        {
            heap.assign(nums.begin(), nums.begin()+k);
            make_heap(heap.begin(), heap.end(), greater<>());
            for(int i=k; i<nums.size(); i++)
            {
                add(nums.at(i));
            }
        }
    }
    
    int add(int val) {
        if(heap.size()<=kth-1) 
        {
            heap.push_back(val);
            if(heap.size()==kth)
            {
                make_heap(heap.begin(), heap.end(), greater<>());
                return heap.front();
            }
            else return -1;
        }
        else 
        {
            if(val>heap.front())
            {
                pop_heap(heap.begin(), heap.end(), greater<>());
                heap.back() = val;
                push_heap(heap.begin(), heap.end(), greater<>());
            }
            return heap.front();
        }
    }
private:
    vector<int> heap;
    int kth;
};
```