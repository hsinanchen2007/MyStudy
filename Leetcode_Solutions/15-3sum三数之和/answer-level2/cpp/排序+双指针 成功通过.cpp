我尽力了!
```
#include<algorithm>
using std::sort;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> temp;
        if(nums.size()<3) return result;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        if(nums[0]>0) return result;
        if(nums[len-1]<0) return result;
        if(nums[0]==0 && nums[len-1]==0)
        {
            vector<int> t= {0, 0, 0};
            result.push_back(t);
            return result;
        }
        int low;
        int high;
        for(int i=0;i<len;++i)
        {
            low = i+1;
            high = len-1;
            while(low<high)
            {
                if(nums[i]+nums[low]+nums[high]>0) --high;
                else if(nums[i]+nums[low]+nums[high]<0) ++low;
                else
                {
                    vector<int> v = {nums[i], nums[low], nums[high]};
                    temp.insert(v);
                    --high;
                }
                //cout<<"i, low, high  "<<i<<' '<<low<<' '<<' '<<high<<endl;
            }
        }
        result.assign(temp.begin(),temp.end());
        return result;
    }
};
```
