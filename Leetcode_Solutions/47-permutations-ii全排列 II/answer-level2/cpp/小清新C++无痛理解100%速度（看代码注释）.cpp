```
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;

        recur(res,nums);

        return res;
    }

    void recur( vector<vector<int>>&res,vector<int>&nums,int decide = 0){
        //参数时引用的，decide暗示目前要确定的nums的下标


        //如果已经所有的数字都已确定则加入结果的集合
        if(decide == nums.size()){
            res.push_back(nums);
        }

        //这个set记录了哪些值已经和目前要确定的位置交换过，用来过滤相同的
        //如 【2 2 1 1】 decide = 0时， 会有2个1和位置0交换
        set<int> help; 
        for(int i = decide; i < nums.size();i++){
            if(i==decide || nums[i] != nums[decide]){  //nums[i] == nums[decide]时，交换也后一样
                if(!help.count(nums[i])){
                    swap(nums[i],nums[decide]); //交换
                    recur(res,nums,decide+1);   //递归
                    swap(nums[i],nums[decide]); //恢复
                    help.insert(nums[i]);       //存储已经和该位置交换过的值，注意是值而不是下标
                }
            }
        }

    }
};
```
