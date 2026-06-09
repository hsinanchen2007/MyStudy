### 解题思路

怎么总感觉 `sort` 最快？？

可能我的排序太垃圾了。

### 代码

```cpp

// 快速排序
class Solution {
    /* 快速排序
    void quickSort(vector<int>& nums, int low, int high) {
        if(low < high) {
            int pivotpos = Partition(nums, low, high);
            quickSort(nums, low, pivotpos - 1);
            quickSort(nums, pivotpos + 1, high);
        }
    }
    int Partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        while(low < high) {
            while(low < high && nums[high] >= pivot) --high;
            nums[low] = nums[high];
            while(low < high && nums[low] <= pivot) ++low;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }
    */

    // 堆排序
    void sink(vector<int> &a, int index, int size) {
        while(index * 2 + 1 < size) {//是否已经是叶子节点
            int j = index * 2 + 1;          
            if(j < size && j+1 < size && a[j+1] > a[j]) 
                j++;
            if(a[index] >= a[j]) break;
            swap(a[index], a[j]);
            index = j;
        }
    }
    //给定一个数组，建立大根堆
    void heapify(vector<int> &a) {
        int size = a.size();
        for(int i = size / 2 - 1; i >= 0; i--) {//size/2 -1 是最后一个非叶子节点，它以下都是叶子节点，不用下沉了
            sink(a, i, size);
        }
    }
    void heapSort(vector<int> &a) {
        int N = a.size();
        heapify(a);//建立大根堆
        while(N > 1) {
            swap(a[0], a[--N]);//选择最大元素（根）
            sink(a, 0, N);//修复堆
        }
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        
        // int left = 0;
        // int right = arr.size() - 1;
        // quickSort(arr, left, right);

        heapSort(arr);
        for(int i = 0; i < k; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};
```