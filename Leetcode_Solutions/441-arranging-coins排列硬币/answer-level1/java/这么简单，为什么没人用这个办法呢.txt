```java
// n -= i, 直到减到小于等于当前行数，说明当前到了最后一行
// O(lonN)
public int arrangeCoins(int n) {
    int row = 0;
    while(true){
        row++;
        n -= row;
        if(n <= row) break;
    }
    return row;
}
```

```