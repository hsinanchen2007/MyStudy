直接递归实现f(k) = max(f(k – 2) + A,f(k – 1))会引起堆栈溢出，需要消除重复递归分支。
```
class Solution {
public:
    int call(int k, vector<int>& nums){
        if(k==0)
            return nums[0];
        if(k == -1)
            return 0;
        if(reco.count(k))
            return reco[k];//直接返回已经计算过的情况
        reco.insert(pair<int,int>(k,max(call(k-2,nums)+nums[k],call(k-1,nums))));//将已计算情况保存
        return reco[k];
    }
    int rob(vector<int>& nums) {
        return call(nums.size()-1,nums);
    }
private:
    unordered_map<int,int> reco;
};
```
