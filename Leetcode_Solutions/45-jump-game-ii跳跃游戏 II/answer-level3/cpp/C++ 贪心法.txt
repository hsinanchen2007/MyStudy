这里我用的是贪心法，helper[i] 代表nums[i] 位置可以到达的最远下标，最多不超过nums.size()-1。当然也可以降低空间复杂度，将helper数组设置成一个单位。供参考吧！
```
class Solution {
public:
    int jump(vector<int>& nums) {
        int n_size = nums.size();
        int j_cnt = 0;
        vector<int> helper(n_size,0);//helper[i] 代表nums[i] 位置可以到达的最远下标
        for(int i=0;i<n_size;i++){
            helper[i] = (nums[i] + i) >= n_size-1 ? n_size-1 : (nums[i] + i);
        }
        
        int pos = 0;
        while(pos != n_size-1){
            int next_jm = helper[pos];
            int next_i = helper[pos];
            for(int i=pos+1;i<=helper[pos];i++){
                if(next_jm < helper[i]){
                    next_jm = helper[i];
                    next_i = i;
                }
            }
            j_cnt++;
            pos = next_i;
        }
        return j_cnt;
    }
};
```
