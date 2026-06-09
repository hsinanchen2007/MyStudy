public:
    int binaryGap(int N) {
        if(N<3)
            return 0;
        int c=N, y=0;
        int x1, x2=0, k=0,res=0;
        bool flag=true;
        while(c/2)
        {
            k++;
            y=c%2;
            if(y)
            {
                if(flag)
                {
                    x1=k;
                    flag=false;
                }
                x2=k;
                res=max(res,x2-x1);
                x1=x2;
            }
            c=c/2; 
        }
        if(c)
        {
            if(flag)
                return 0;
            k++;
            x2=k;
            res=max(res,x2-x1);
        }
        return res;
    }
};