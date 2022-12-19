### 解题思路
分享一波混乱计算

### 代码

```c
int f(long mod, long digit) {
    if (mod == digit) return 1;
    else if (mod < digit) return 0;
    else if (mod-digit >= digit) return digit;
    else return mod-digit+1;
}

int countDigitOne(int n){
    /* 在j位上，每i个数里会出现j个1*/
    long i = 10;
    long j = 1;
    
    long count = 0; 
    long num = (long)n;

    while (1) {
        count += num/i*j+f(num%i,j);
        if (num/i==0) break;
        i *= 10; j *= 10;
    }

    return count;
}
```