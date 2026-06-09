```
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int res=0,cnt=1;
        for (int f: flowerbed){
            if (f==1) {res+=(cnt<3)?0:(cnt-1)/2;cnt=0;}
            else cnt++;
        }
        res+=(++cnt<3)?0:(cnt-1)/2;
        return res>=n;
    }
```
