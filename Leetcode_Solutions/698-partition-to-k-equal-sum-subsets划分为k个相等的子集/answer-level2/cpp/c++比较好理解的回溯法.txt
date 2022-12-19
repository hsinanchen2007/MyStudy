### 解题思路
回溯法其实就是暴力解，尝试所有组合可能，但适当的剪枝可以加快程序
具体见备注

效率不算高，但参数少比较好理解，有其他剪枝方法可以给我评论，我学习一下

### 代码

```cpp
class Solution {
public:
    //设置两个全局变量，少传两个参数
    vector<bool> visited;
    int target;//要凑的目标值
    bool f(vector<int>& nums,int cur,int n){//cur是现在这次已经凑了多少，n为还要凑几次
        if( n == 0 ) return true;//全部凑好了，返回true
        bool isok;
        for(int i=nums.size()-1;i>=0;i--){
            if(!visited[i] && nums[i]+cur <= target ){//剪枝：cur + nums[i]居然比target大，不要
                visited[i]=true;
                if(nums[i]+cur == target){//诶，发现刚好凑好一组
                    isok=f(nums,0,n-1);
                }
                else{
                    isok = f(nums,cur+nums[i],n);//更新cur,继续开始
                }
                if(isok) return true;
                visited[i]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto n :nums) sum+=n;
        if( k == 0 || sum%k != 0) return false;
        target = sum/k;
        sort(nums.begin(),nums.end());
        if(nums[nums.size()-1] > target ) return false;
        visited=vector<bool>(nums.size(),false);
        return f(nums,0,k);

        //贪心 错误！，不具有贪心选择性质
        //例如[10,10,10,7,7,7,7,7,7,6,6,6]
        //3
        // int sum = 0;
        // for(auto n :nums) sum+=n;
        // if( k == 0 || sum%k != 0) return false;
        // int target = sum/k;
        // vector<int> a(k,0);
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<k;j++){
        //         if(a[j]<target && a[j]+nums[i] <= target ){
        //             a[j]+=nums[i];
        //             break;
        //         }        
        //     }
        // }
        // for(int i=0;i<k;i++){
        //     if(a[i]!=target)
        //         return false;
        // }
        // return true;
    }
};
```