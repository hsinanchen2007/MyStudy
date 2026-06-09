```
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        count = 0;
        for(auto num:nums){
            insert(num);
        }
    }
    
    int add(int val) {
        insert(val);
        return heap[0];
    }
private:
    void insert(int val){
        if(count < k){
            count++;
            heap.push_back(val);
            adjustHeapUp(count-1);
        }
        else{
            if(val <= heap[0])
                return;
            else{
                heap[0] = val;
                adjustHeapDown(0);
            }
        }
        return;
    }
    void adjustHeapDown(int i){
        //i节点子节点是2i+1,2i+2
        while(2*i+1 < count){
            int j = 2 * i + 1;
            //找到子节点中小的节点
            if(2*i+2<count && heap[2*i+2] < heap[j])
                j += 1;
            if(heap[i] <= heap[j])
                return;
            swap(heap[i],heap[j]);
            i = j;
        }
        return;
    }
    void adjustHeapUp(int i){
        //i节点父节点是(i-1)/2
        while(i > 0){
            int j = (i-1)/2;
            if(heap[j] <= heap[i])
                return;
            swap(heap[i],heap[j]);
            i = j;
        }
        return;
    }
    vector<int> heap;
    int k;
    int count;
};
```
