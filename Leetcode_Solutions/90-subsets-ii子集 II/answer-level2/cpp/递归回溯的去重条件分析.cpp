此题目与78.子集的区别在于允许了重复元素，那么此题目的关键就在于如何去重。
重复元素对答案造成影响主要在于定长解中前一个元素用到了，后一个元素又用一次
首先，我们保证输入数据是有序的，这样保证重复的元素都挨着。
以上面[1,2,2]为例
其解空间的图如下
```
[]->[1]->[1,2],[1,2](deleted)->[1 2,2]
    [2]->[2,2]
    [2](deleted)
```
我们需要注意，
```
dfs(nums,start,tmp,res)
{
    res.push_back(tmp);            
    for(int i=start;i<nums.size();i++)
    {
        tmp.push_back(nums[i]);
        dfs(nums,i+1,tmp,res);
        tmp.pop_back();
    }
}
```
这里每一个dfs只负责一个长度的解，比如第一个dfs的for循环生成的解就是[1],[2],[2]，即负责构成空集之后的一个解元素
而在`tmp.push_back(nums[0])`之后的dfs生成的解则是[1,2],[1,2]，即负责构成1之后的第二个解元素
此dfs中再调用的dfs则负责构成前面结果基础上的第三个解元素，
以此类推。

那么，回到去掉重复元素的话题上，刚刚的重复来自于第一个解元素已经选择了一次，又选择一次，即当前要选择的元素和上一个要选择的元素重复了
同样[1,2]也是第二个解元素选了一次又选一次。
```
[]->[1]->[1,2],[1,2](deleted)->[1 2,2]
    [2]->[2,2]
    [2](deleted)
```
所以去重条件应该是
```
if(i!=start&&nums[i]==nums[i-1])
    continue;
```
这里的i!=start表示从第二个解元素开始，如果和前一个元素一样，则放弃这个候选答案

完整代码如下
```
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {        
        vector<vector<int>> res;
        if(nums.size()==0)
            return res;
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        subsetsWithDup(nums,0,tmp,res);
        return res;        
    }
    void subsetsWithDup(const vector<int>& nums,int start,vector<int>& tmp,vector<vector<int>>& res)
    {
        res.push_back(tmp);            
        for(int i=start;i<nums.size();i++)
        {
            if(i!=start&&nums[i]==nums[i-1])
                continue;
            tmp.push_back(nums[i]);
            subsetsWithDup(nums,i+1,tmp,res);
            tmp.pop_back();
        }
    }
};
```
