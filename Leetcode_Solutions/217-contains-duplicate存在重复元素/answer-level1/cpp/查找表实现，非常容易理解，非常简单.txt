class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>record; //建立查找表

        for(int i=0;i<nums.size();i++){
            if(record.find(nums[i])!=record.end()){//每次循环就判断当前查找表中是否有这个元素，如果没有就插入到查找表，如果有就返回true
                return true;
            }

            record.insert(nums[i]);
        }
        return false;
    }
};