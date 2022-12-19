```
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set<int> myset(nums.begin(), nums.end());
        int res = 0;
        int num, x;
        unordered_set<int>::iterator prev_it;
        
        for(unordered_set<int>::iterator it = myset.begin(); it != myset.end();){
            num     = *it;
            prev_it = myset.find(num - 1);
            if(prev_it == myset.end()){
                x   = num;
                do{
                    myset.erase(it);     // 删除连续子序列中当前值
                    ++x;
                    it = myset.find(x);  // 找到连续子序列中下一个值
                }while(it != myset.end());
                res = max(res, x-num);
                it  = myset.begin();     // 下一个连续子序列
            }
            else{
                it = prev_it;  // 找到连续子序列中前一个值
            }
        }
        return res;
    }
};
```
