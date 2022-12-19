1. 快排
```
#include <experimental/random>

class Solution {
public:
    int count = 0;
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()>1) 
            quickSort(nums, 0, nums.size()-1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if (l < r){
            int pos = _partition(nums, l, r);
            quickSort(nums, l, pos - 1);
            quickSort(nums, pos + 1, r);
        }
    }
    int _partition(vector<int>& v, int l, int r){
        if (l==r) return l;
        int idx =  std::experimental::randint(l, r); //随机选择pivot

        swap(v[l], v[idx]); //将pivot交换到首位置

        int j = l; //慢指针
        idx = l+1; //快指针
        while(idx <= r){
            if(v[idx] < v[l]) swap(v[idx], v[++j]); //将小于pivot的数据按顺序排序，
            idx++;
        }
        swap(v[l], v[j]); //将pivot插入到正确位置

        return j;
    }
};
```
2. 堆排序
```
class Solution {
public:

    //堆排序 heap sort
    vector<int> sortArray(vector<int>& nums) {
        HeapSort(nums, nums.size());;
        return nums;
    }   
    void max_heapify(vector<int>& Array, int start, int end) {
        int dad = start;
        int son = dad + dad + 1;

        while(son <= end) {
            if(son + 1 <= end && Array[son] < Array[son+1])
                son++;
            if(Array[dad] > Array[son])
                return;
            else{
                swap(Array[son], Array[dad]);
                dad = son; //比较dad节点及其son节点， 将最大值交换到dad节点，并向后代搜索。
                son = dad + dad + 1;
            }
        }
    }
    void HeapSort(vector<int>& Array, int size) {
        for(int i=size/2-1; i>=0; i--)
            max_heapify(Array, i, size-1); //初始化，从最后一个父节点开始，确保数组的最大值在第一个父节点上；

        for(int i=size-1; i>0; i--){
            swap(Array[0], Array[i]); //将最大值交换到数组末尾
            max_heapify(Array, 0, i-1);
        }
    }
};
```
3. 归并排序
```
class Solution {
public:
    //归并排序--迭代版
    vector<int> sortArray(vector<int>& nums) {
        return MergeSort1(nums, nums.size());
    }   
    vector<int> MergeSort1(vector<int> nums, int size) {
        vector<int> copy = nums;
        for(int seg=1; seg<size; seg+=seg){
            for(int start=0; start<size; start+=seg+seg){
                int low = start, mid = min(start+seg, size), high = min(start+seg+seg, size);
                int k = low;

                int start1 = low, start2 = mid;
                int end1 = mid, end2 = high;

                while(start1<end1 && start2<end2)
                    copy[k++] = nums[start1]<nums[start2] ? nums[start1++] : nums[start2++];

                while(start1<end1)
                    copy[k++] = nums[start1++];
                while(start2<end2)
                    copy[k++] = nums[start2++];                
            }
            nums = copy;
        }
        return copy;
    }

};
```
```
class Solution {
public:
    //归并排序--递归版
    vector<int> sortArray(vector<int>& nums) {
        MergeSort2(nums, 0, nums.size()-1);;
        return nums;
    }   
    void Merge(vector<int> &Array, int front, int mid, int end) {
        vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid + 1);
        vector<int> RightSubArray(Array.begin() + mid + 1, Array.begin() + end + 1);
        
        int idxLeft = 0, idxRight = 0;

        LeftSubArray.push_back(numeric_limits<int>::max());
        RightSubArray.push_back(numeric_limits<int>::max());
        //cout<<'a';
        for (int i = front; i <= end; i++) {
            if (LeftSubArray[idxLeft] < RightSubArray[idxRight]) {
                Array[i] = LeftSubArray[idxLeft];
                idxLeft++;
            } else {
                Array[i] = RightSubArray[idxRight];
                idxRight++;
            }
        }
    }

    void MergeSort2(vector<int> &Array, int front, int end) {
        if (front >= end)
            return;
        int mid = front + (end - front) / 2;
        MergeSort2(Array, front, mid);
        MergeSort2(Array, mid + 1, end);
        Merge(Array, front, mid, end);
    }

};
```


