```
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> um;
        for(int i=0;i<nums.size();i++) um[nums[i]].push_back(i);
        int nums_du=0,minlen;
        for(auto i:um){
            int size=i.second.size();
            if(size>=nums_du){
                int temp=i.second[size-1]-i.second[0]+1;
                if(size>nums_du){
                    nums_du=size;
                    minlen=temp;
                }
                else minlen=min(minlen,temp);
            }
        }
        return minlen;
        
}
};
static const auto io_speed_up=[]{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

```
