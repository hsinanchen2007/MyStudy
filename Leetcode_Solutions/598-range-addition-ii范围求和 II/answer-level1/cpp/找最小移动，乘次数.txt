int maxCount(int m, int n, vector<vector<int>>& ops) 
    {
        int k=ops.size();
        int a=m,l=n;
        for(int i=0;i<k;i++)
        {
            a=min(a,ops[i][0]);
            l=min(l,ops[i][1]);
        }
        return a*l;
    }