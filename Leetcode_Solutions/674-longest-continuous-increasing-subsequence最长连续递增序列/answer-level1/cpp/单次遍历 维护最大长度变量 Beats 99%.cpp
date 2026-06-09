![image.png](https://pic.leetcode-cn.com/eab3a380c99d3aa6603d7a6c88765c114d706b44923699b75f22b4a1366a9061-image.png)

````
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // edge case 
        if(nums.size()==0) return 0;

        int cur_cnt = 1, max_cnt = 1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]<nums[i+1])
                cur_cnt++;
            else{
                max_cnt = max(cur_cnt,max_cnt);
                cur_cnt = 1;
            }
        }

        max_cnt = max(cur_cnt,max_cnt);  // if all elements are increasing
        return max_cnt;
    }
};
```
