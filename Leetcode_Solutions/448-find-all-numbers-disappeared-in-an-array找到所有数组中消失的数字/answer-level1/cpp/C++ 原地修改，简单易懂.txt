### 解题思路
1. 首先将nums加入一个-1，使其下标为0~n,以便于数字n的保存
2. 我们从0开始，每次都尝试把当前位置上的数字放到他该在的位置上，即`nums[i]=i`
     这个时候就会出现这么几种情况：
        （1）当前在位置i，且nums[i]=i,则继续往前走
        （2）当前在位置i，当前位置上的数字为nums[i]
              * 有可能nums[i]为-1，此时也继续往前走
              * nums[i]这个数字的老家的数字为nums[nums[i]]，这个时候把nums[i]和nums[nums[i]]的数字对调，
              *     但是i不前进，只有nums[i]=i或者nums[i]=-1的时候i才前进
最终时间复杂度O(N),空间复杂度O(1),即原地修改

但是最终用时击败98%, 但内存消耗击败5%。。。。很奇怪，明明没有申请额外的空间啊

### 代码

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int cnt = 0;
        nums.push_back(-1);
        while(cnt < nums.size()){
            if(nums[cnt] == cnt || nums[cnt] == -1){
                cnt++;
                continue;
            }
            int num_at_cnt = nums[cnt];
            if(num_at_cnt == nums[num_at_cnt]){
                nums[cnt] = -1;
                cnt++;
            }else{
                nums[cnt] = nums[num_at_cnt];
                nums[num_at_cnt] = num_at_cnt;
            }
        }
        vector<int> ans;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != i){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```