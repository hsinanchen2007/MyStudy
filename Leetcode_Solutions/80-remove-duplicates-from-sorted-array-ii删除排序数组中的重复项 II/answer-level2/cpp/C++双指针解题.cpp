```


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int pslow = 0,pfast = 0;
        int cur = nums[0],count = 0;
        while(pfast < nums.size()){
            count = nums[pfast]==cur ? count + 1 : 1;
            if( count <= 2){
                cur = nums[pfast];
                nums[pslow++] = nums[pfast++];   
            }    
            else
                pfast++;
        }
        nums.resize(pslow);
        return pslow;
        
    }
};
```

![image.png](https://pic.leetcode-cn.com/c660f7f1008e0c518901f8a39a8ef72e7d800f68bcde163de5748b4e19a57297-image.png)
效果还不错