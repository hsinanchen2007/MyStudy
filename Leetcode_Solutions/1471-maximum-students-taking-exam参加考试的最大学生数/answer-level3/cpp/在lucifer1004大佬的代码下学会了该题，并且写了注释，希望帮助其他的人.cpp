







        int m=seats.size();
        int n=seats[0].size();
        vector<vector<int>> dp(m+1,vector<int>(1<<n));//初始化m+1行，记录每行的所有状态，第一行记录在第1行，第0行全为0便于计算

        for(int row=1;row<=m;row++){//从第一行开始
            for(int s=0;s<(1<<n);s++){//遍历2^n个状态
                bitset<8> bs(s);//记录对应状态的bit位
                bool ok=true;
                for(int j=0;j<n;j++){
                    if((bs[j] && seats[row-1][j]=='#') || (j<n-1 && bs[j] && bs[j+1])){//不能坐在坏椅子上也不能在同一行相邻坐
                        ok=false;
                        break;
                    }
                }
                if(!ok){
                    dp[row][s]=-1;//说明坐在坏椅子上或相邻坐了，该状态舍弃
                    continue;
                }
                for(int last=0;last<(1<<n);last++){//找到一种当前行的可行状态后，遍历上一行的所有状态
                    if(dp[row-1][last]==-1)//上一行的状态被舍弃了，那就直接下一个状态
                        continue;
                    bitset<8> lbs(last);
                    bool flag=true;
                    for(int j=0;j<n;j++){
                        if(lbs[j] && ((j>0 && bs[j-1]) || (j<n-1 && bs[j+1]))){//如果找到的这个上一行状态的j位置做了人，
                            flag=false;                                    //下一行的j+1位置或j-1位置也坐了人，那么该状态不合法，舍弃
                            break;
                        }
                    }
                    if(flag){//flag为真说明这个last状态的每个位置都合法
                        dp[row][s]=max(dp[row][s],dp[row-1][last]+(int)bs.count());//转移方程
                    }
                }

            }
        }
        int res=0;
        for(int i=0;i<(1<<n);i++){//在最后一行的所有状态中找出最大的
            if(dp[m][i]>res){
                res=dp[m][i];
            }
        }
        return res;

