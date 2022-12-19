```
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt=0,i=0,j=1;
        sort(nums.begin(),nums.end());
        map<int,bool>hashtable;
        while(i<nums.size()&&j<nums.size()){
            if(nums[j]-nums[i]==k&&(hashtable.find(nums[i])==hashtable.end()||hashtable.find(nums[j])==hashtable.end())){
                cnt++;
                hashtable[nums[i]]=true;
                hashtable[nums[j]]=true;
                j++;
            }
            else if(nums[j]-nums[i]<k) j++;
            else {
                i++;
                if(i==j) j++;
            }
        }
        return cnt;
    }
};
```
用双指针一次遍历，用哈希表来剔除重复数字的影响
