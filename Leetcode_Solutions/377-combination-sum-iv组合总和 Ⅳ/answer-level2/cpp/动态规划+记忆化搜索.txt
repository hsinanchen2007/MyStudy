思路：第一想法就是暴搜,从数组的第一个数开始，搜索使用第一个数字，看能有多少种方案可以使总和恰好为target，然后继续算用以第二个数字作为第一数字能有多少种方案可以使综合恰好为target,以此类推。这种方法的弊端非常明显，如果target比数组的数都大很多的话，递归深度太深了会超时，所以果然TEL了。后面想到可以做记忆化，用ans记录总和恰好等于target的所有方案数，所以有状态转移方程：
ans[target]=ans[target−current]+count
其中current表示target之中的状态，count表示总和恰好为current时有多少种方案。
```c++
//超时代码
class Solution {
public:
    int count;
    int combinationSum4(vector<int>& candidates, int target) {
        dfs(target,target,candidates);
        return count;
    }
    void dfs(int target,int remain,vector<int>& candidates){
        if(remain<0)return;
        if(remain==0){
            count++;
            return;
        }
        for(int i = 0;i<candidates.size();i++){
            dfs(target,remain - candidates[i],candidates);
        }
    }
};
```
```c++
//加了记忆化的代码
class Solution {
public:
    vector<long long> temp;
    long long count;
    int combinationSum4(vector<int>& candidates, int target) {
        temp = vector(target+1,-1ll);
        for(int i=1;i<=target;i++){
            count=0;
            dfs(i,i,candidates);
            temp[i]=count;
        }
        return count;
    }
    void dfs(int target,int remain,vector<int>& candidates){
        if(remain<0)return;
        if(temp[remain]!=-1){//如果还要凑的数已经算过了则加上当前方案数之和返回即可。
            count+=temp[remain];
            count%=INT_MAX;//防止超出整数的表示范围
            return;
        }
        if(remain==0){
            count++;
            return;
        }
        for(int i = 0;i<candidates.size();i++){
            dfs(target,remain - candidates[i],candidates);
        }
    }
};
```