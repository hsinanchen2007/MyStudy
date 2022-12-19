### 解题思路
//回溯（尝试或者试探）深搜 求最短的题目类用宽搜
//遍历所有节点 之类的题目bfs dfs均可（小岛的个数）
//这道题就是经典dfs问题 用搜索功能
//剪枝操作有三个：排序，计算和是否能被4整除，在dfs放入之前判断是否大于边长
### 代码

cpp
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size()<4)return false;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }if(sum%4!=0){//
            return false;
        }
        sort(nums.rbegin(),nums.rend());
        //最神奇的一个操作(rebgin,rend)反向迭代器
        //排序的原因是为了使大的数字优先放 会减少排序次数
        int bucket[4]={0};
        return generate(0,sum/4,nums,bucket);
    }
    bool generate(int i,int target,vector<int>& nums,int bucket[]){
        if(i==nums.size()){
            return bucket[0]==target&&bucket[1]==target&&bucket[2]==target&&bucket[3]==target;
        }
        for(int j=0;j<4;j++){
            if(bucket[j]+nums[i]>target){//如果某个边长大于target就不放了
                continue;
            }
            bucket[j]+=nums[i];
            if(generate(i+1,target,nums,bucket)){
                return true;
            }
            bucket[j]-=nums[i];
        }
        return false;
    }
};

