class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % k != 0) return false;
        //每个子集的值
        int target = sum/k;
        //定义一个数组，去除已经访问过的元素
        vector<bool> visited(nums.size(), false);

        //0表示从位置0开始，在数组中找到和为sum的子集
        //k表示这是要在数组中寻找k个子集
        //这里其实有两个层次的迭代；
        //迭代1：k， k-1,即在数组中寻找k个子集
        //迭代2：0， 1，即在数组中从位置0开始， 找寻一个子集为target的数组
        //      例如， 如果target是10， nums[0]= 2, 递归调用，在nums[1] 后面找等于10-2的子集
        //      （这是第二次递归）
        return dfs(nums, visited, 0, target, 0, k);
        
    }

    //k,k-1,..., 1的过程是一次递归
    //start, start+1, ... , nums.size()的过程是一次递归
    bool dfs(const vector<int>& nums, vector<bool>& visited, int start, int target, int sum, int k)
    {
        //递归终止条件
        //设置第一次递归的终止条件， k == 1的时候，就表示成功分配了
        if(k == 1) return true;
        //设置第二次递归的终止条件, 第二次递归结束，表示在k次找到子集，要进入到k-1次寻找子集
        if(sum == target) return dfs(nums, visited, 0, target, 0, k-1);
        else if(sum > target) return false;
        else{
            for(int i = start; i < nums.size(); i++)
            {   //排除已经分配过多元素
                if(!visited[i])
                    {
                        visited[i] = true;
                        //表示如果在i+1 之后的数组中找到x + nums[i] == target的话，就说明能找到，返回true
                        if(dfs(nums, visited, i+1, target, sum+nums[i], k)) return true;
                        visited[i] = false;

                    }
            }
            return false;
        }     
    }
};