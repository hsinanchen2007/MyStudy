双指针，分别指向头尾
如果头为奇数，头加1，头为偶数，交换头尾值，尾减一，继续判断头
```
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0,right = nums.size()-1;
        while(left<right){
            if(nums[left]%2)
                left++;
            else{
                swap(nums[left],nums[right]);
                right--;
            }
        }
        return nums;
    }
};
```
找到奇数和前面换就是
```
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]&1)
                swap(nums[i],nums[left++]);
        return nums;
    }
};
```
