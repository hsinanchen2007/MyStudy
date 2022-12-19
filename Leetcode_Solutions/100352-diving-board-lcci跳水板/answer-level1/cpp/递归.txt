#### 递归

更新时间4-8:12:41

更新时间4-8:12:11

更新时间4-8:10:18

时间 5.75% 内存 100%

注：
1.思考之后，发现由于参数限制和返回值限制无法做到知用一个函数递归写完。
2.思路从爆搜转向递推公式

思路：
1.公式枚举可能直接放入set去重
3.放入vec数组
4.vec排序

```cpp
class Solution {
public:
vector<int> ans;
set<int> Set;
    void dfs(int shorter, int longer, int k,int u)
    {
        if(u<0)return;
        int t = shorter*(k-u)+longer*u;
        if(!Set.count(t)&&t)Set.insert(t);
        dfs(shorter,longer,k,u-1);
    }

    vector<int> divingBoard(int shorter, int longer, int k) {
        dfs(shorter,longer,k,k);

        for(auto op:Set)ans.push_back(op);   
        sort(ans.begin(),ans.end());
        return ans;
    }
};