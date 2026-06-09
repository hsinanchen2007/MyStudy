```
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int beg = 4;
        for(int i=1;i<sz;i++){
            if(nums[i]==nums[i-1] && nums[i]!=0)
                return false;
        }
        for(int i=0;i<sz;i++){
            if(nums[i] != 0){
                beg = i;
                break;
            }
        }
        return nums[sz-1]-nums[beg]<5;
    }
};
```

这里判定逻辑很多简单：
第一条：
    如果数组中有非零重复元素，则不可能构成顺子，立即返回
第二条：
    找到数组中的非零最小值，和非零最大值，判定max-min<5?，成立则返回true,反之false
