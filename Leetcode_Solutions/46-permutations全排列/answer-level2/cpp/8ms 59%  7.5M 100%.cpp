基本思路就是选定从空开始，依次选定nums中的数插入到当前解的各个间隔
当可行解与给定数字序列size相同时 因为不会重复插入 所以说明每个数都插入过了 插入到res中
回溯实现就是删除递归前插入的nums[i] 
```
class Solution {
private:
    vector<vector<int>> res; //结果
    vector<int> sol; //单次可行解
    vector<int> nums;//给定数字序列
    int len;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        len = nums.size();
        helper(0); //从nums[0]开始
        sort(res.begin(), res.end()); //为了顺序输出 不排序也行
        return res;
    }
private:
    void helper(int i){
        if(sol.size() == len){//终止条件  可行解与给定数字序列size相同 说明每个数都插入过了
            res.push_back(sol);
            return;
        }
        int temp = sol.size();
        for(int j=0; j<=temp; j++){//当前sol的所有间隔插入当前nums[i]
            sol.insert(sol.begin()+j, nums[i]);//向量中迭代器指向元素前增加一个元素x
            helper(i+1);//插入当前值后进行递归 到num[i+1] 或 返回
            sol.erase(sol.begin()+j); //回溯， 删除插入的当前值， j++后当前值插入下一个间隔
        }
    }
};
```
