![image.png](https://pic.leetcode-cn.com/25bf41bcf7aa4f41d5cc10d07095a5ea6c5debe3975d870a4aadce59a9ff763d-image.png)

单次遍历，记录最大值、第二大值和最大值索引
```
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        // edge case
        if(nums.size()==1) return 0;

        int max_num = INT_MIN;
        int sec_max_num = INT_MIN;
        int idx_max = -1; 
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>max_num){
                sec_max_num = max_num;
                max_num = nums[i];
                idx_max = i;
            }
            else if(max_num!=nums[i] && nums[i]>sec_max_num){
                sec_max_num = nums[i];
            }
        }
        // cout<<sec_max_num<<endl;
        // cout<<max_num<<endl;


        if(max_num>=2*sec_max_num)
            return idx_max;
        else
            return -1;
    }
};
```

