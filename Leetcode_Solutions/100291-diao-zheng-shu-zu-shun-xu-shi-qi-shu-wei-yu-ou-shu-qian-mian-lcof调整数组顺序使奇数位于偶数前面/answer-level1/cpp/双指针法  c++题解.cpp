使用两个指针，第一个left指针从头往后移动，第二个right指针从后往前移动。当left指针指向偶数，right指针指向奇数时，交换两个数字。

```
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<right){
            while(left<right&&(nums[left]%2!=0)){
                left++;
            }
            while(left<right&&(nums[right]%2==0)){
                right--;
            }
            if(left<right){
                int temp=nums[left];
                nums[left]=nums[right];
                nums[right]=temp;
            }
        }
        return nums;
    }
};
```

