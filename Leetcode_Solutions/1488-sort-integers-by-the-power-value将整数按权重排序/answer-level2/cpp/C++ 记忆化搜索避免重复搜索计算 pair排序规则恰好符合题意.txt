```cpp
    int w[1000010];//记忆化数组
    int get(int x){//求数x的权重
        if(x==1) return 0;
        if(w[x]) return w[x];//若该状态算过了 直接返回
        return w[x] = x&1 ? get(3*x+1)+1 : get(x/2)+1;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> a;
        for(int i = lo; i <= hi; i++) a.push_back({get(i),i});
        sort(a.begin(),a.end());
        return a[k-1].second;
    }
```
