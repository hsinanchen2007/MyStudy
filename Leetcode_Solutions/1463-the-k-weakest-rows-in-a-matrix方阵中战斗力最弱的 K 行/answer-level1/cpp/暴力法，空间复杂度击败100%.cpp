```
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> v(mat.size());
        vector<int> vv(k);
        for(int j=0;j<mat.size();j++)
        {
            for(int i=0;i<mat[j].size();i++)
            if(mat[j][i]) v[j]++;    //求出每行战斗力
        }
        vector<int> res(v);         //复制v
        sort(v.begin(),v.end());     //战斗力从小到大排序
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<mat.size();j++)
            {
                if(res[j]==v[i])    //排序之后和排序之前比较
                {
                    vv[i]=j;         //把排序之前的索引假如res
                    res[j]=-1;      //-1使相同的战斗力消除，不在参与比较
                    break;
                }
            }
        }
        return vv;
    }
};
```
