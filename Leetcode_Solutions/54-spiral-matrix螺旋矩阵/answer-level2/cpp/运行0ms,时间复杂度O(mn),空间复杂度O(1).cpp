        vector<int> res;
        int m=matrix.size();
        if(m==0)
            return res;
        int n=matrix[0].size();
        
        int times=min(m&1?m/2+1:m/2,n&1?n/2+1:n/2);
        
        for(int i=0;i<times;i++){
            int x=i,y=i;
            int mt=m,nt=n;
            res.push_back(matrix[x][y]);
            for(int j=0;j<nt-1;j++){
                y++;
                res.push_back(matrix[x][y]);
            }

            for(int j=0;j<mt-1;j++){
                x++;
                res.push_back(matrix[x][y]);
            }

            if(mt!=1)
            for(int j=0;j<nt-1;j++){
                y--;
                res.push_back(matrix[x][y]);
            }

            if(nt!=1)
            for(int j=0;j<mt-2;j++){
                x--;
                res.push_back(matrix[x][y]);
            }

            m-=2;
            n-=2;

        }
        return res;