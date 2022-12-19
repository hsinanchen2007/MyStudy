### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> num;
        int len=nums.size();
        if(len<4){
            return num;
        }
        sort(nums.begin(),nums.end());
        int i,low,high;
        for(i=0;i<len-3;i++){
            int c=target-nums[i];
            for(int j=i+1;j<len-2;j++){
                low=j+1;
                high=len-1;
                
                int n=c-nums[j];
                while(low<high){
                    int lo=nums[low];
                    int hi=nums[high];
                    if(lo+hi==n){
                        vector<int> a{nums[i],nums[j],nums[low],nums[high]};
                        num.push_back(a);
                        while(low<high&&lo==nums[low]){        //去重
                            low++;
                        }
                        while(low<high&&nums[high]==hi){       //去重
                            high--;
                        }
                    }
                    else if (lo + hi < n){
                        low++;
                    }
                    else if (lo + hi > n){
                        high--;
                    }
                }
                while (j + 1 < len-2 && nums[j] == nums[j + 1])        //去重
                {
                    j++;
                }
            }
            while (i + 1 < len-3 && nums[i] == nums[i + 1])          //去重
            {
                i++;
            }
        }
        return num;
    }
};
```