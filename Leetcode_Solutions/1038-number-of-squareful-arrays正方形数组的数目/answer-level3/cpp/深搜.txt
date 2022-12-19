class Solution {
public:
    bool st[12];
    double eps = 1e-6;
    int ans;
    bool check(int a)
    {
        return sqrt(a) - ((int)sqrt(a)/1)<eps;
    }
    void dfs(vector<int> &A,int pre,int cur,int &ans)
    {
        if(cur==A.size()) 
        {
            ans++;
            return;
        }
        bool m[12]; //判断同一层中是否出现相同的
        memset(m,0,sizeof m);
        for(int i=0;i<A.size();i++)
        {
            if(st[i]) continue;
            if(cur>0&&!check(pre+A[i])) continue; 
            bool flag = false;
            for(int j=0;j<i;j++)
            {
                if(m[j]&&A[j]==A[i])
                {
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            st[i] = true;
            dfs(A,A[i],cur+1,ans);
            st[i] = false;
            m[i] = true;
        }
    }
    int numSquarefulPerms(vector<int>& A) {
        int len = A.size();
        int ans = 0;
        int t = 0;
        //if(check(8)) cout<<"fuck"<<endl;
        dfs(A,0,0,ans);     //当前的前一位 当前的数字数量
        return ans;
    }
};