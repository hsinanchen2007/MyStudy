```
public static int maxCoins(int[] nums) {
        int [][]d=new int[nums.length+2][nums.length+2];
        int []a=new int [nums.length+2];
        for(int i=1;i<a.length-1;i++){
            a[i]=nums[i-1];
        }
        a[0]=1;
        a[a.length-1]=1;
        for(int i=0;i<a.length;i++){
            d[i][i]=0;
        }
        for(int i=2;i<a.length;i++){
            for(int j=0;j<a.length-i;j++){
                for(int k=j+1;k<j+i;k++){
                    d[j][j+i]=Math.max(d[j][j+i],d[j][k]+d[k][j+i]+a[j]*a[k]*a[j+i]);
                }
            }
        }
        return d[0][a.length-1];

    }
```
