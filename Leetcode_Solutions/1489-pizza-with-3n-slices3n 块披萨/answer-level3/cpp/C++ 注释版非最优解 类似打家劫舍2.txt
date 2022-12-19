```
    //易知 第一块和最后一块不可能同时取到，可把环形转为直线型来算:
    //1.去除最后一块再算最大值 2.去除第一块再算最大值 3.结果即为max(1,2)
    //对于直线型则类似打家劫舍
    //dp状态表示:
    //  f[i][j] 表示 对于前i块披萨 取j块时的最大值
    //dp状态计算:
    //  则f[i][j] = max(f[i-1][j],f[i-2][j-1]+a[i]);//按照第i块披萨不取或取来分类
    int f[510][510],n; 
    int maxSizeSlices(vector<int>& a) {
        n = a.size();
        //cout<<slove(a,0,n-2)<<" "<<slove(a,1,n-1);
        return max(slove(a,0,n-2),slove(a,1,n-1));//两种情况取最值max(1,2)
    }
    int slove(vector<int>& a, int s, int e){//计算a数组中下标从s到e的披萨的不相邻最大和(取(cnt-1)/3+1个时) 
        int cnt = e-s+1;//披萨总数
        if(cnt<0) return 0;
        if(cnt==1) return a[s];
        if(cnt==2) return max(a[s],a[s+1]);
        memset(f,0,sizeof f);
        f[s][1] = a[s],f[s+1][1] = max(a[s],a[s+1]);//一个披萨时即为其值 两个披萨时取最大的那个
        for(int i = s+2; i <= e; i++){//考虑前i个披萨时
            for(int j = 1; j <= (i-s)/2+1; j++){//取j个披萨 对于len个披萨 最多取(len-1)/2+1个披萨 带入即可  
                f[i][j] = max(f[i-1][j],f[i-2][j-1]+a[i]);
            }
        }
        return f[e][(cnt-1)/3+1]; 
    }
```
