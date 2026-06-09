```
    public int[] divingBoard(int shorter, int longer, int k) {
        if(k==0) return new int[0];
        if(shorter==longer) return new int[]{k};
        int[] res=new int[k+1];
        for(int i = 0;i <= k; i++)
            res[i]=longer*i+shorter*(k-i);
        return res;
    }
```
