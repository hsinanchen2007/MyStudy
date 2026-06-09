第一次没参考大家的答案写回溯，还是一次性AC，有点激动。
我在回溯专题里按顺序刷了以下几道题：
Q1.全排列
Q2.全排列Ⅱ
Q3.组合总和
Q4.组合总和Ⅱ
Q5.组合
发现题目居然是一样的，除Q1外，都涉及到初始数组排序，去重。而做回溯，画出递归树，真的很重要，之前就是偷懒不愿意画，回溯一直不会写。
这道题也不例外，先排序再回溯同时保证去重。区别在于，上述几道题，是从根节点一直到叶子节点，并将叶子节点作为结果保存，这题是所有节点全都要保存。

```
class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()==0) return res;
        sort(nums.begin(),nums.end());
        res.push_back(temp);
        backtrack(nums,0);
        return res;
    }

    void backtrack(vector<int>& nums,int start){

        if(temp.size()==nums.size()){
            return;
        }
        
        for(int i=start;i<nums.size();++i){//去重的精髓1---start规定了数组内搜索的起始点
            temp.push_back(nums[i]);
            res.push_back(temp);//因为选择一个值放入temp中，就要把temp保存到res中

            backtrack(nums,i+1);//去重的精髓2---i+1保证了自身不会被重复利用
            temp.pop_back();
        }
    }
};
```

执行用时：击败94.48%
内存消耗：击败31.67%

题解中很多朋友提出了其他的方法，我也看了，觉得对于我的情况而言，能够熟练掌握回溯并写出代码成功AC就已经足矣。
（任重而道远，题目还要继续刷）
