与easy的那一题有些许差别，在那一题的代码上做一点改动

```
class Solution {
public:
    //维护指针i，j
    //指针i表示[0,i]区间的元素为确定放进最终结果的元素集合
    //j表示当前遍历的元素，判断是否加进结果集合
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int i;
        int j;
        for(i=0,j=1;j<nums.size();j++){
            if(nums[j]!=nums[i]||(!(i>0&&nums[i]==nums[i-1]))){
                //if里的判断为：当前元素不等于nums[i]并且nums[i]!=nums[i-1]
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};
```
时间：O(n)
空间：O(1)
