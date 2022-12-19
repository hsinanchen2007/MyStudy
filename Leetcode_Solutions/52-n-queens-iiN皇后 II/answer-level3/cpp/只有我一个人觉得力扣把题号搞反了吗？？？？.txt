# 只有我一个人觉得力扣把题号搞反了吗？？？？


```
class Solution {
public:
    int N;
    int total=0;
    int totalNQueens(int n) {
        N=n;
        vector<int> ans(n);
        find(0,ans);
        return total;
    }
    void find(int n,vector<int> &ans)
    {
        if(n==N) 
        {
            //cout<<"1"<<endl;
            total++;
            return;
        }
        
        for(int i=0;i<N;i++)//只考虑行,对于这N列来说
        {
            int ok=1;
            for(int j=0;j<n;j++)
            {
                if(ans[j]==i || abs(ans[j]-i)==abs(j-n))//在一对角上或者在一行上
                {
                    ok=0;
                    break;
                }
 
            }
            if(ok)//没有冲突
                {
                    ans[n]=i;
                    find(n+1,ans);
                }
        }
    }
};
 
 
```
