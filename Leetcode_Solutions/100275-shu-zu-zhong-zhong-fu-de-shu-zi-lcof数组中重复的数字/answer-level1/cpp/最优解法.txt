###思路
一次遍历，希望将每个数放在和下标相同的地方，如果当前的数不是该下标的对应数字，就把这个数送到它给去的地方，把对方的数字换过来，不行就再换，直到可以为止。重复就是在交换时发现对方坑里已经有相同的数了。

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0 || nums[i]>=n)
            return -1;
        }

        for(int i=0;i<n;i++){
            while(i!=nums[i] && nums[nums[i]]!=nums[i])//需要交换而且 对方坑有位置就交换
                swap(nums[i],nums[nums[i]]);
            if(i!=nums[i] && nums[nums[i]]==nums[i])//我方坑里需要交换，对方坑已经有人了
            return nums[i];
        }

        return -1;
    }
};
```