1. 采用双指针，从数组尾部开始遍历；
2. i用于遍历，j用于指向最后一个不等于val的数组值；
3. 当 nums[i] == val 时，把最后一个不等于val的数组值（即nums[j]）填充到nums[i]上，并且j--;
4. 最后返回j+1的值。

```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=nums.size()-1, i=j;
        for(; i>=0 ; i--){
            if(nums[i] == val ){
                if(nums[j] == val)
                    j--;
                else
                    nums[i] = nums[j--];
            }
        }
        return j+1;
    }
};
```
