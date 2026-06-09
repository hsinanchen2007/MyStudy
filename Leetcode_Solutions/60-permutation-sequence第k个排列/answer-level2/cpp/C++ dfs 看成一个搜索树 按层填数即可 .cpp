```
    string ans;
    //填写第u层时(初始为第n层)的第k个排列 该层需要填的数 d为当前层可以填的数 f为阶乘常量
    void dfs(int u, int k, vector<int> &d, vector<int> &f){
        if(u==0) return;//填写完毕
        int x = (k-1)/f[u-1];//当前层该填的数的下标 
                            //因为当前层有u-1个分支,每一个分支的大小(排列数)都是 f[u-1]
                            //所以看k落入哪个分支下 下标就是几 注意下标从0开始
        ans += d[x] + '0';//填入
        d.erase(d.begin()+x);//该数已被占用 删除
        dfs(u-1,(k-1)%f[u-1]+1,d,f);//到下一层 u减一 k变为在下一层的第(k-1)%f[u-1]+1个排列
    }
    string getPermutation(int n, int k) {
        vector<int> d(n),f(n+1);//d为可以填的数 f为阶乘常量
        f[0] = 1;
        for(int i = 1; i <= n; i++) d[i-1] = i, f[i] = i*f[i-1]; 
        dfs(n,k,d,f);
        return ans;
    }
```
