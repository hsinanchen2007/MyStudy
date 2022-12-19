### 解题思路
原始思路是统计每个元素的个数，然后挑出个数最大的元素，如果不在查个数的时候维护最大值而是在查完个数在维护，这样会超时，嗯嗯嗯，就这个点比较好，然后头脑要灵活，纠结了半天未知元素个数数组的初始化。。。

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int val=0,count=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>count){
                count=mp[nums[i]];
                val=nums[i];
            }
        }
    return val;
        /*vector<int> a;
        int val;
        for(int i=0;i<nums.size();i++){
            a[nums[i]]++;
        }
        for(int j=0;j<a.size();j++){
            if(a[j]>nums.size()/2)
            val=j;
        }
        return val;*/
    }
};
```