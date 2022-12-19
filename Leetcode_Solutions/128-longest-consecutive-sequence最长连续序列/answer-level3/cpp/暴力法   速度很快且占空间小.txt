```
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     if(nums.size()==0)
        return 0;
     sort(nums.begin(),nums.end());
     int max_length=0,temp_length=0;
     for(int i=1;i<nums.size();i++){
         if(nums[i]==nums[i-1]+1){
                temp_length++;
         }else if(nums[i]==nums[i-1]){
             //会存在相等的情况 此时什么都不需要做
             continue;
         }
         else{
             if(temp_length>max_length)//更新max_length的值
                max_length=temp_length;
             temp_length=0;//重置temp_length的值
         }

     }
        return (temp_length>max_length?temp_length:max_length)+1;

    }
};
```
