这个代码就不用过多解释了吧，不熟悉堆的话，先熟悉下堆的内容再来看
耗时和内存都是90左右
```
class KthLargest {
private:
    bool g_is_head_sorted = false;
    vector<int> g_top_k_heap;
    int g_k = 0;
public:
    //维护一个最小堆，容量为k，堆顶为最小值
    void heap_update(int pos, int last_pos) {
        int dad = pos;
        int son = 2 * dad + 1;
        while (son <= last_pos) {
            if (son + 1 <= last_pos and g_top_k_heap[son + 1] < g_top_k_heap[son]) {
                ++son;
            }
            if (g_top_k_heap[son] < g_top_k_heap[dad]) {
                int temp = g_top_k_heap[dad];
                g_top_k_heap[dad] = g_top_k_heap[son];
                g_top_k_heap[son] = temp;
            }
            else {
                break;
            }
            dad = son;
            son = 2 * dad + 1;
        }
    }
    
    void heap_initial() {
        // 1, 2, 3, 4, 5
        int last_father = g_top_k_heap.size() / 2 - 1;
        for (int i = last_father; i >= 0; --i) {
            heap_update(i, g_top_k_heap.size() - 1);
        }
    }
    
    void heap_update_top(int new_value) {
        if (new_value > g_top_k_heap[0]) {
            g_top_k_heap[0] = new_value;
            heap_update(0, g_top_k_heap.size() - 1);
        }        
    }
    
    KthLargest(int k, vector<int>& nums) {
        g_k = k;
        for(int i = 0; i < nums.size(); ++i) {
            if (g_top_k_heap.size() == k) {
                if (g_is_head_sorted == false) {
                    heap_initial();
                    
                    g_is_head_sorted = true;
                }
                heap_update_top(nums[i]);
            }
            else {
                g_top_k_heap.push_back(nums[i]);
            }
        }

    }
    
    int add(int val) {
        if (g_top_k_heap.size() != g_k) {
            g_top_k_heap.push_back(val);
            heap_initial();    
        }
        else {
            heap_update_top(val);
        }
        return g_top_k_heap[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```
