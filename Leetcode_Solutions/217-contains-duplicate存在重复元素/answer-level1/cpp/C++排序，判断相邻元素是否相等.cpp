```
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
        思路：
        0.要进行异常判断，如果nums的长度为0，直接返回false（不写，会通不过，因为有一个测试案例是[]）
        1.排序
        2.判断相邻元素是否相等
        */
        if(nums.size()==0){
            return false;
        }
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]==nums[i+1]){
                //等
                return true;
            }
        }
        
        return false;
    }
};
```
