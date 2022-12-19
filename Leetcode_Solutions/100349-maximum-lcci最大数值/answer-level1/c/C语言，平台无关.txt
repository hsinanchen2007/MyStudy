```
int maximum(int a, int b){
    unsigned long temp = (long)a - (long)b;
    temp = temp >> (sizeof(unsigned long) * 8 - 1);

    return (1 - temp) * a + temp * b;
}
```
