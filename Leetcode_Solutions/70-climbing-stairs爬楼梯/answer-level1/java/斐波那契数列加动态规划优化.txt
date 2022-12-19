```
public static int solution1(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        else {
            int [] resule = new int[n+1];
            resule[0]=1;
            resule[1]=1;
            for(int i=2;i<=n;i++){
                resule[i] = resule[i-1]+resule[i-2];
            }
            return resule[n];
        }
    }
```
