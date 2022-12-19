```
class Solution {
    vector<vector<int>> res;
    void dfs(vector<int> m)
    {
        res.push_back(m);
        for(int i=m[m.size()-2];i<=sqrt(m[m.size()-1]);++i)
        {
            if(m[m.size()-1]%i==0) 
            {
                vector<int> temp(m.begin(),m.end()-1);
                temp.push_back(i);
                temp.push_back(m[m.size()-1]/i);
                dfs(temp);
            }
        }
         
    }
public:
    vector<vector<int>> getFactors(int n) {
        for(int i=2;i<=sqrt(n);++i)
        {
            if(n%i==0)
            {
                vector<int> temp({i,n/i});
                dfs(temp);
            }
        }
        return res;
    }
};
```
- 执行用时 :4 ms, 在所有 C++ 提交中击败了85.82% 的用户
- 内存消耗 :8.7 MB, 在所有 C++ 提交中击败了98.04%的用户

思路：比如说24，主函数把他拆成了两个数的乘积2x12、3x8、4x6（只需要判断到n的平方根即可），递归函数中的核心是将当前数组输出到结果中，并将**最后一个数**进行拆分，注意最后一个数拆分出的因子必须必前一个数的要小，比如4x16只能拆成4x4x4而不能在拆出比4小的数，这样输出的每一个结果都是非递减数组，并进行了剪枝。