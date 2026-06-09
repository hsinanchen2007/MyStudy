```
    int tr[100010],great[210],low[210];//tr为树状数组 每个数左边大于该点的个数 小于该点的个数
    int Max;
    int lowbit(int x){
        return x & -x;
    }
    int ask(int x){//求下标1~x的前缀和
        int ans = 0;
        for(; x; x -= lowbit(x)) ans += tr[x];//x-lowbit(x)即为子节点的右端点
        return ans;
    }
    void add(int x, int y){//下标x处值+y 则只会影响其祖先节点的值
        for(; x <= Max; x += lowbit(x)) tr[x] += y;
    }
    int numTeams(vector<int>& a) {
        int n = a.size();
        Max = 0;
        for(int i = 0; i < n; i++) Max = max(Max,a[i]);//值域最大值
        for(int i = 0; i < n; i++){//每个数左边大于x的个数 小于x的个数
            int x = a[i];//a的下标从0开始 以a的值域建立树状数组
            great[i] = ask(Max) - ask(x);//大于x的数的个数
            low[i] = ask(x-1);//小于x的数的个数
            add(x,1);
        }
        memset(tr,0,sizeof tr);
        int res1 = 0, res2 = 0;
        for(int i = n-1; i > 0; i--){//右边的大于x 和小于x
            int x = a[i];
            res1 += low[i] * (ask(Max) - ask(x));//左小右大 单增类型
            res2 += great[i] * ask(x-1);//左大右小 单减类型
            add(x,1);
        }
        return res1 + res2;
    }
```
