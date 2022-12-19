```Java
public boolean hasGroupsSizeX(int[] deck) {
    int[] count = new int[10000];
    for (int i: deck) {
        count[i]++;
    }

    int res = -1;
    
    for (int c: count) {
        if (c > 0) {
            if (res == -1) {
                res = c;
            } else {
                res = gcd(res, c);
            }
        }
    }
    return res >= 2;
}

int gcd(int a, int b) {
    return b == 0 ? a: gcd(b, a % b);
}
```
