```
    int p[100010];//并查集数组
    int find(int x){//寻找x的根
        if(x!=p[x]) p[x] = find(p[x]);
        return p[x];
    }
    int makeConnected(int n, vector<vector<int>>& c){
        int r = 0;//多余的线缆个数
        for(int i = 0; i < n; i++) p[i] = i;//并查集数组初始化
        for(auto v : c){
            int a = v[0],b = v[1];
            int x = find(a), y = find(b);
            if(x!=y) p[x] = y;//合并
            else r++;//说明此线多余
        }
        int t = 0;
        for(int i = 0; i < n; i++) {//求出图中连通分量的个数t
            if(find(p[i])==i) t++; 
        }
        return r<t-1 ? -1:t-1;//需要t-1根线 多余的线不足时则为-1
    }
```
