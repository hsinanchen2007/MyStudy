### 解题思路
    //设置两个指针位于数组的一前一后，每当前面的扫描到偶数时停止，后面的扫描到奇数时停止
    //交换两个指针指向的数，直到两个指针相遇或者相差一为止，复杂度0(n)解题思路

### 代码

```cpp
class Solution {

public:
    vector<int> exchange(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            if(nums[low]%2==0&&nums[high]%2==1)
               swap(nums[low], nums[high]);
            else if (nums[low]%2==1)
               low++;
            else high--;
        }
        return nums;

    }
};
```