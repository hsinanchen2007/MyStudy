```java
public int integerReplacement(int n) {
    return help((long)(n));
}

public int help(long n){
    if(n <= 3) return (int)n - 1;
    if(n % 2 == 0)
        return 1 + help(n / 2);
    else{
        if( (n - 1) / 2 % 2 == 0)
            return 2 + help((n - 1)/2);
        else
            return 2 + help((n + 1)/2);
    }
}
```