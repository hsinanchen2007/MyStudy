
```
    int n=-1;
    List<Integer> resu=new ArrayList();
    public List<Integer> grayCode(int n) {
        this.n=n;
        digui(0,0,true);
        return resu;
    }


    public void digui(int prev,int cur,boolean flag){
        if(cur>=n){
            resu.add(prev);
            return;
        }
        if(flag){
            digui(prev<<1,cur+1,true);
            digui((prev<<1)+1,cur+1,false);
        }else{
            digui((prev<<1)+1,cur+1,true);
            digui(prev<<1,cur+1,false);
        }
    }

```
