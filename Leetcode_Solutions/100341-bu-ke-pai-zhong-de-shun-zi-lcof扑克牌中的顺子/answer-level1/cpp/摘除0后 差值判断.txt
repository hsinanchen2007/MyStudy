将0单独拿出来后排序，相邻元素之间的差值-1为需要0元素的个数，如果0元素不够，直接返回false
```
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int zero=0;
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) {
                zero++;
                continue;
            }
            else temp.push_back(nums[i]);
        }
        int sz=temp.size();
        int pre=temp[0];
        bool ok1=true;
        int zero1=zero;
        for(int i=1;i<sz;i++){
            if(temp[i]==pre) return false;
            if(temp[i]!=pre+1) zero1-=temp[i]-pre-1;
            pre=temp[i];
            if(zero1<0) {
                ok1=false;
                break;
            }
        }
        return ok1;
    }
};
```
