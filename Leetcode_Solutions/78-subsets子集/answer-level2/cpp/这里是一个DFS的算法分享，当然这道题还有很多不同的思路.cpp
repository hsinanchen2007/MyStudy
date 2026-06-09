class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> list;
        int num = nums.size() - 1;
        dfs(nums,num,0,result,list);
        return result;       
    }
    //整个过程是一直沿着二叉树向下探寻
    //需要包含的要素：遍历数组的大小，现在走到的位置，result，list
        void dfs(vector<int> nums,int num,int n,vector<vector<int>>& result, vector<int> list)
    {
        //先写递归基
        if(n==num) 
        {   
            result.push_back(list);//不选
            list.push_back(nums[n]);//选
            result.push_back(list);
            return;
        }
        else  
        {            
            dfs(nums,num,n+1,result,list);//不选进入下一阶段 
            list.push_back(nums[n]);//选
            dfs(nums,num,n+1,result,list);
        }  
    }
};