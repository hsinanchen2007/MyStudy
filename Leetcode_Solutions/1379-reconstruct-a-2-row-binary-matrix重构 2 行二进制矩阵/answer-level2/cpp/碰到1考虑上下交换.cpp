思路：
初始时，第0行全部放1（和为uu），第1行全部放0(和为ll)；
利用 flag 标记列和为0和2的列，更新uu和ll；
对于列和为1的情况，遍历，若当前uu > upper，则对应列上下翻转，减小uu；否则break;
检查uu==upper ll==lower
```
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) 
    {
        int n=colsum.size();
        if(n==0)
            return {};
        vector<bool> flag(n,false);
        vector<vector<int>> res={vector<int>(n,1),vector<int>(n,0)};
        int uu=n,ll=0;
        for (int i=0;i<n;++i)
        {
            if(colsum[i]==2)
            {
                res[1][i]=1;flag[i]=true;
                ++ll;
            }
            else if(colsum[i]==0)
            {
                res[0][i]=0;flag[i]=true;
                --uu;
            }
        }
        for (int i=0;i<n;++i)
        {
            if(!flag[i])
                if(uu>upper)
                {
                    swap(res[0][i],res[1][i]);
                    ++ll;--uu;
                }
                else 
                    break;
        }
        if(uu==upper && ll==lower)
            return res;
        else
        {
            res.clear();
            return res;
        }

    }
};
```
