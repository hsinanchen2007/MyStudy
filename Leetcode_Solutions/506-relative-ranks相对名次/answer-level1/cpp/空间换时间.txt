将数组排序，用map来记录当前数字对应的名次
```
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int size=nums.size();
        vector<int>temp(nums.begin(),nums.end());
        vector<string>res(size,"");
        unordered_map<int,int>map;
        sort(temp.begin(),temp.end());
        for(int i=0;i<size;i++){
            map[temp[i]]=size-i;
        }
        for(int i=0;i<size;i++){
            if(map[nums[i]]==1)res[i]="Gold Medal";
            else if(map[nums[i]]==2)res[i]="Silver Medal";
            else if(map[nums[i]]==3)res[i]="Bronze Medal";
            else res[i]=to_string(map[nums[i]]);
        }
        return res;
    }
};
```
