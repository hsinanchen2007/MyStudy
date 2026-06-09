其实左开右闭能够解决绝大部分问题。而且非常清晰。
```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 左开右闭通常能解决绝大部分问题    
        // [0, k) is 0s
        // [k, i) is 1s
        // [i, j) is unknown
        // [j, size) is 2s
        
        int k = 0, i = 0, j = nums.size();
        while(i != j) { // if i == j, there's no unknown number
            if(nums[i] == 0) 
                swap(nums[i++], nums[k++]);
            else if(nums[i] == 1) 
                ++i;
            else 
                swap(nums[i], nums[--j]);
        }
    }
};
```
