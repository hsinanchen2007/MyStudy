```
    public int numTrees(int m) {
        int G[] = new int[m+1];
        G[0] =1;
        G[1] =1;
        for(int n=2;n<=m;n++){
            for(int i=1;i<=n;i++){
                G[n] += G[i-1] * G[n-i];
            }
        }
        return G[m];
    }
```
