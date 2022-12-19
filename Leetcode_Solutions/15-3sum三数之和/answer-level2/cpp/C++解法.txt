方法一：将三数之和简化为两数之和
```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> dict;
        vector<vector<int>> result={};
        sort(nums.begin(), nums.end());

        for(int i=0; i<size; i++)
            dict[nums[i]] = i;
        
        for(int i=0; i<size; i++){
            for(int j=i+1; j<size; j++){
                if(dict.find(0-nums[i]-nums[j]) != dict.end() && dict[0-nums[i]-nums[j]] > j){
                    vector<int> tmp={nums[i],nums[j],nums[dict[0-nums[i]-nums[j]]]};
                    
                    if(!result.size()) 
                        result.push_back(tmp);
                    else{
                        int flag=1;
                        for(int k=0; k<result.size(); k++){
                            if(tmp==result[k]) flag=0;
                        }
                        if(flag) result.push_back(tmp);
                    }
                }
            }
        }
        return result;
    }
};
```
