### 解题思路
解法与三数之和类似，无须赘述。需要指出的一点，借鉴了一个java版的方案，那就是在指针遍历前有一个对当前解最小最大两个最值得判断，可以免去不必要的循环

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int num_size = nums.size();
        if(nums.size()<4) return result;
        sort(nums.begin(), nums.end());
        for(int i=0; i< nums.size()-3; i++){
            //if(nums.at(i)>target) return result;
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            if(nums[i]+nums[num_size-3]+nums[num_size-2]+nums[num_size-1]<target) continue;
            for(int j=i+1; j<nums.size()-2; j++){
                //if(nums.at(i)+nums.at(j)>target) break;
                if(nums[j]==nums[j-1] && j-i>1) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
                if(nums[i]+nums[j]+nums[num_size-2]+nums[num_size-1]<target) continue;
                int low = j+1; int high = nums.size()-1;
                
                while(low<high){
                    if(nums[i]+nums[j]+nums[low]+nums[high]==target){
                        result.push_back({nums[i],nums[j],nums[low],nums[high]});
                        low++; while(nums[low]==nums[low-1] && low<high) low++;
                        high--; while(nums[high]==nums[high+1] && low<high) high--;
                    
                    }else{
                        if(nums.at(i)+nums.at(j)+nums.at(low)+nums.at(high)>target){
                            high--; while(nums[high]==nums[high+1] && low<high) high--;
                        }else{
                            low++; while(nums[low]==nums[low-1] && low<high) low++;
                        }
                    }
                    
                }
            }
        }
        return result;
    }
};
```