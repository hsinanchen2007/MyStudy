### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void Adjust(vector<int>& arr,int size,int parent)
    {
        int child = parent*2+1;
        while(child <size)
        {
            if(child+1<size&& arr[child+1]>arr[child])
                child++;
            if(arr[parent]<arr[child])
                swap(arr[parent],arr[child]);
            parent = child;
            child = parent*2+1;
        }
    }
    void HeapSort(vector<int>& arr)
    {
        for(int i = arr.size()/2-1;i>=0;--i)
            Adjust(arr,arr.size(),i);
        for(int i = arr.size()-1;i>0;--i)
        {
            swap(arr[i],arr[0]);
            Adjust(arr,i,0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() == 1 || nums.size()==0)
            return nums;
        HeapSort(nums);
        return nums;
    }
};
```