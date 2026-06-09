### 解题思路
此处撰写解题思路
先排右边j，再排左边i。num[j] > mid 或者用 >= ， 这个不重要。
### 代码

```cpp
class Solution {
public:

    void quickSort(vector<int>& nums, int l, int r){
        if(l>=r) return;
        int mid = nums[l];
        int i = l;
        int j = r;
        while(i<j){
            while(i<j && nums[j] > mid) j--;
            if(i<j) nums[i++] = nums[j];
            while(i<j && nums[i] < mid) i++;
            if(i<j) nums[j--] = nums[i];
        }
        nums[i] = mid;
        quickSort(nums, l, i-1);
        quickSort(nums, i+1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
```