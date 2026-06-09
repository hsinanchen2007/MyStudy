class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        int degree = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(m[nums[i]].size() == 0){
                vector<int> vec(3,0);
                vec[0] = 0;
                vec[1] = i;
                vec[2] = i;
                m[nums[i]] = vec;
            }
            m[nums[i]][0] += 1;
            degree = max(degree,m[nums[i]][0]);
            m[nums[i]][2] = i;
        }

        int result = INT_MAX;
        for(auto p : m){
            if((p.second)[0] == degree){
                result = min(result,(p.second)[2] - (p.second)[1] + 1);
            }
        }
        return result;
    }
};