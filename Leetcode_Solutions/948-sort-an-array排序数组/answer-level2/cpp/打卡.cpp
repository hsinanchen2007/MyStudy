
### 代码

```cpp
class Solution {
public:
    void shiftdown(vector<int>& nums, int idx, int end)
    {
        while(idx*2+1<end)
        {
            int bigger = idx*2+1;
            if(bigger+1<end && nums[bigger]<nums[bigger+1]) bigger++;
            if(nums[idx]>nums[bigger]) break;
            swap(nums[idx], nums[bigger]);
            idx = bigger;
        }
    }
    //堆排序
    void heapSort(vector<int>& nums)
    {
        for(int i = nums.size()/2-1; i>=0; i--)
            shiftdown(nums, i,nums.size());
        for(int i = nums.size()-1; i > 0; i--)
        {
            swap(nums[0],nums[i]);
            shiftdown(nums, 0, i);
        }
    }
    //归并排序
    vector<int> copy;
    void mergeSort(vector<int>& nums, int start, int end)
    {
        if(start+1==end) return;
        int mid = (start + end) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid, end);
        copy = nums;
        int i = start, j = mid;
        while(i < mid && j < end)
        {
            if(copy[i]<copy[j]) nums[start++] = copy[i++];
            else nums[start++] = copy[j++];
        }
        while(i<mid) nums[start++] = copy[i++];
        while(j<end) nums[start++] = copy[j++];
    }
    //快排
    void quickSort(vector<int>& nums, int l, int r)
    {
        if(l>=r) return;
        int idx = rand()%(r-l+1)+l;
        int pivot = nums[idx];
        swap(nums[idx], nums[l]);    
        int lt = l+1;
        int gt = r;
        while(1)
        {
            while(lt <= r && nums[lt] < pivot) lt++;
            while(gt > l  && nums[gt] > pivot) gt--;
            if(lt >= gt) break;
            swap(nums[lt++], nums[gt--]);
        }
        swap(nums[l], nums[gt]);
        quickSort(nums, l, gt-1);
        quickSort(nums, gt+1, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        //堆排序
        // heapSort(nums);

        //归并排序
        // mergeSort(nums, 0, nums.size());

        //快排
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
};
```