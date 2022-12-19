感觉自己的代码虽然复杂，但应该很容易理解。
用dpMin数组，记录从 **左** 开始到当前最小值的下标
用dpMax数组，记录从 **右** 开始到当前最大值的下标

这样从1,size-1这个区间开始扫描，很容易就能判断是否符合了。
代码入下:

```cpp
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        vector<int> dpMin(nums.size()+3,0);
        vector<int> dpMax(nums.size()+3,0);
        for(int i=0;i<nums.size();++i){
            if(i == 0)
                dpMin[i] = i;
            else if(nums[i] < nums[dpMin[i-1]]){
                dpMin[i] = i;
            }
            else{
                dpMin[i] = dpMin[i-1];
            }
        }
        for(int i=nums.size()-1;i>=0;--i){
            if(i == nums.size()-1)
                dpMax[i] = i;
            else if(nums[i] > nums[dpMax[i+1]])
                dpMax[i] = i;
            else
                dpMax[i] = dpMax[i+1];
        }
        for(int i=1;i<nums.size()-1;++i){
            int l = dpMin[i],r = dpMax[i];
            if(l < i && i < r && nums[l] < nums[i] && nums[i] < nums[r])
                return true;
        }
        return false;
    }
};
```