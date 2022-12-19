- 思路：
  - 对每个元素分别进行选择或者不选择，构造2^n个子集
  - !!! 对于重复元素，不同数量的重复元素选且只选一次
    - 例如：[1,2,2,2,3]
    - 1: []  初始只包含空集
    - 2: [] [1] 上一轮集合的集合+加入 加入新元素1的集合
    - 3: [] [1] [2] [1,2] 加入 加入新元素2的集合
    - 3: [] [1] [2] [1,2] [2,2] [1,2,2] 加入 加入新元素2,2的集合
    - 3: [] [1] [2] [1,2] [2,2] [1,2,2] [2,2,2] [1,2,2,2] 加入 加入新元素2,2,2的集合
    - (步骤3有三步，是因为2出现三次)
    - 4：[] [1] [2] [1,2] [2,2] [1,2,2] [2,2,2] [1,2,2,2] 上一轮集合的集合+
         [3] [1,3] [2,3] [1,2,3] [2,2,3] [1,2,2,3] [2,2,2,3] [1,2,2,2,3] 加入 加入新元素3的集合
- 时间复杂度：
  - o(n*2^n)
- 空间复杂度：
  - o(2^n)
- 结果:
  - 用时：68%（8ms）
  - 内存：23%
```
class Solution {
    vector<vector<int>> res;
    vector<int> tmp;
    void subsetsWithDup_div(int num, int count){
        int end=res.size();
        for(int i=0;i<end;i++){
            for(int j=1;j<=count;j++){
                tmp=res[i];
                for(int k=1;k<=j;k++) tmp.push_back(num);
                res.push_back(tmp);
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int,int> counter;
        for(int i=0;i<nums.size();i++){
            if(counter.count(nums[i])) counter[nums[i]]++;
            else counter[nums[i]]=1;
        }
        res.push_back(tmp);
        for(auto const& c:counter) subsetsWithDup_div(c.first, c.second);
        return res;
    }
};
```
