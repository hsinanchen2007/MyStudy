```
class Solution {
    public int sumNums(int n) {
        boolean b = (n == 0) || ((n += sumNums(n - 1)) > 0);
        return n;
    }
}
```

```
class Solution {
    public int sumNums(int n) {
        boolean b = (n > 0) && ((n += sumNums(n - 1)) > 0);
        return n;
    }
}
```



