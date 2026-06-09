```
int bitwiseComplement(int N){
    if (N == 0) return 1;
    unsigned int m = N;
    while ((m & (m - 1)) != 0) m &= (m - 1);
    m = (m << 1) - 1;
    return ~N & m;
}
```
