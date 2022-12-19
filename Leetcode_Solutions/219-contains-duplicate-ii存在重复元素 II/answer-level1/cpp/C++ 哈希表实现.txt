```
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool flag=false;
        map<int,int>hashtable;
        for(int i=0;i<nums.size();++i){
            if(hashtable.find(nums[i])!=hashtable.end()){
                if(abs(hashtable[nums[i]]-i)<=k){
                    flag=true;
                    break;
                }
            }
            hashtable[nums[i]]=i;
        }
        return flag;
    }
};
```
用哈希表记录元素的索引，一次遍历数组，当发现两个相同元素时，比较索引差的绝对值与k的大小，确定flag
