思想与官方思路相似，空间多余了，只需要保留两个状态量就行
```
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()<3) return *max_element(nums.begin(),nums.end());
        vector<int> vec;//纪录之前的最佳结果，多余了
        vec.push_back(nums[0]);
        vec.push_back(nums[1]);
        for(int i=2;i<nums.size();++i){
            vec.push_back(findmax(vec)+nums[i]);
        }
        return *max_element(vec.begin(),vec.end());
    }
    int findmax(vector<int> vec){
        int res=vec[0];
        for(int i=1;i<vec.size()-1;++i){
            if(vec[i]>res) res=vec[i];
        }
        return res;
    }
};
```
