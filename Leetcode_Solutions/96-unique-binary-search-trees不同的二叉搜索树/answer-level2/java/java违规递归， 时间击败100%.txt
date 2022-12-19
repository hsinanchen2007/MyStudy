```java
    public int numTrees(int n) {
        if(n<0)return 0;
        switch (n){
            case 0:
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 5;
            case 4:
                return 14;
            case 5:
                return 42;
        }
        int res = 0;
        int mid = n / 2;
        for (int i = 1; i <= mid; i++) {
            res += (numTrees(i - 1) * numTrees(n - i));
        }
        res *= 2;
        if (n % 2 != 0) res += (numTrees(mid) * numTrees(mid));

        return res;
    }
```
