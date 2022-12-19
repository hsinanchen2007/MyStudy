### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void insertSort(vector<int>& nums, int l, int r){
        if(l >= r || l < 0 || r >= nums.size()) return;
        for(int i = l+1;i <= r;i++){
            int num = nums[i];
            int j = i-1;
            while(j >= l && num < nums[j]){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = num;
        }
        return;
    }
    int partition(vector<int>& nums, int l, int r){
        int m = (l+r) / 2;
        int flag = nums[(l+r)/2];
        nums[m] = nums[l];
        int left = l;
        int right = r;
        while(left < right){
            while(nums[right] >= flag && left < right) right--;
            if(left == right) break;
            nums[left] = nums[right];
            while(nums[left] < flag && left < right) left++;
            if(left == right) break;
            nums[right] = nums[left];
        }
        nums[left] = flag;
        return left;
    }
    void quickSort(vector<int>& nums, int l, int r){
        if(r - l <= 10) insertSort(nums, l, r);
        else{
            int index = partition(nums, l , r);
            quickSort(nums, l, index-1);
            quickSort(nums, index+1, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
```