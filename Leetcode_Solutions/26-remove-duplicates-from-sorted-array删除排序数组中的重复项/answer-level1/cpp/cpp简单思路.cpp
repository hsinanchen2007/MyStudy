以下的代码看起来可能容易点~
思路就是找到第一个不重复的加入到数组中去.
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int k=0;
        while(i<n){
            int j=i;
            while(j<n&&nums[j]==nums[i])
                j++;
            nums[k++]=nums[i];
            i=j;
        }
        return k;
    }
};
```
虽然有两个`while`,容易看出时间复杂度还是$O(n)$