Solution 1:
先建一个容量为k的小根堆, 然后把剩下的大于堆顶的元素和堆顶交换并调整堆，最终的堆顶元素即为第k大值

Solution 2:
用分治思想,使用快排中确定中枢的模块，若当前中枢位置即为第k大值,查找结束，否则向左或向右继续查询


代码:
```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Solution 1: HeapSort
        // heapSort(nums, k); 
        // int len = nums.size();
        // for(int i = k; i < len; ++i){
        //     if(nums[i] > nums[0]) {
        //         swap(nums[i], nums[0]);
        //         heapAdjust(nums, 0, k);
        //     }
        // }
        // return nums[0];
        
        //Solution 2: Division
        int len = nums.size();
        int l = 0, r = len - 1;
        int pos;
        while((pos = pivot(nums, l, r)) != len - k){
            if(pos > len - k) r = pos - 1;
            else l = pos + 1;
        }
        return nums[pos];
    }
    int pivot(vector<int> & nums, int l, int r){
        int v = nums[l];
        while(l < r){
            while(nums[r] >= v && l < r) --r;
            nums[l] = nums[r];
            while(nums[l] <= v && l < r) ++l;
            nums[r] = nums[l];
        }
        nums[l] = v;
        return l;
    }
    void swap(int & a, int & b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    void heapSort(vector<int> & nums, int len){
        for(int i = len / 2 - 1; i >= 0; --i)
            heapAdjust(nums, i, len);
    }
    void heapAdjust(vector<int> & nums, int k, int len){
        int lch = k * 2 + 1, rch = 2 * k + 2;
        if(lch >= len) return;
        int p = lch; 
        if(rch < len && nums[lch] > nums[rch]) p = rch;
        if(nums[k] <= nums[p]) return; 
        swap(nums[k], nums[p]); 
        heapAdjust(nums, p, len);
    }
};

```