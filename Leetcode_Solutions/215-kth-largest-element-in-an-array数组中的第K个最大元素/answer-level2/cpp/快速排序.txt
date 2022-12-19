### 解题思路
快速排序

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int indix = nums.size()-k;
        int low=0,high=nums.size()-1;
        Qsort(nums,low,high);
        return nums[indix];
        }
    
    private : void Qsort(vector<int>& nums,int low,int high){
        int pivot;
        if(low<high){
           pivot= partition(nums,low,high);
           Qsort(nums,low,pivot-1) ;
           Qsort(nums,pivot+1,high) ;
        }
    }
    private : int partition(vector<int>& nums ,int low,int high){
        int pivotkey;
        pivotkey = nums[low];
        while(low<high){
           while(low<high&&nums[high]>=pivotkey) high--;
        swap(nums,low,high);
        while(low<high&&nums[low]<= pivotkey) low++;
        swap(nums,low,high); 
        }
        return low;
    }
    private : void swap(vector<int>& nums, int i, int j) {
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}
};
```