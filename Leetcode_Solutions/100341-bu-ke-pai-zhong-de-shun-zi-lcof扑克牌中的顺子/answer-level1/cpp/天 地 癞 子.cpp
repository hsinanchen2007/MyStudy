先去掉大小王，再进行排序，遇到不是顺子的用0补齐，直到0个数用完
```
bool isStraight(vector<int>& nums) {
        int king=0;
        for(int i=0;i<nums.size();){
            if(nums[i]==0){
                king++;
                nums.erase(nums.begin()+i);
            }
            else i++;
        }
        sort(&nums[0],&nums[nums.size()]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]||nums[i]-nums[i-1]>king+1)return false;
            else king-=(nums[i]-nums[i-1]-1);
        }
        return true;
    }
```
