```
public static int arrangeCoins(int n) {
        int i=1;
        while (n>=i){//n小于该行应有的个数则停止
            n-=i;
            i++;
        }
        return i-1;
    }
```
