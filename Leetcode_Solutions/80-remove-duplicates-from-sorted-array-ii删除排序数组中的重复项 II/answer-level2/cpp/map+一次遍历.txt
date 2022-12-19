1.用了unordered_map来记录元素的个数
2.判断每个元素个数是否大于2，是的话，就删除该元素。同时指针i要-1，判断当前的新元素
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            ++mp[nums[i]];
            if(mp[nums[i]]>2){
                nums.erase(nums.begin()+i,nums.begin()+1+i);
                i--;
            }
        }
        return nums.size();
    }
};
```
