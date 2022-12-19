一开始暴力破解，一串if else，但是代码很粗糙。
后面看了下不同的题解，发现switch取代if else效果更好，而且还有一个是特殊情况的值刚好是大的减去小的（自己做题还是太粗糙，这个规律都没发现）。
```
int chartoint(char a);

int romanToInt(char * s){
    int result = 0;
    for (int n = 0; s[n]; n++)
    {
        if (chartoint(s[n]) < chartoint(s[n+1]) )
        {
            result += (chartoint(s[n+1]) - chartoint(s[n]));
            n++;
        }
        else  
         result += chartoint(s[n]);
    }
    return result;
}

int chartoint(char a) {
    int out;
    switch(a)
    {
        case 'I' : out = 1; break;
        case 'V' : out = 5; break;   
        case 'X' : out = 10; break;
        case 'L' : out = 50; break;
        case 'C' : out = 100; break;
        case 'D' : out = 500; break;
        case 'M' : out = 1000; break;
    }
    return out;
}
```
