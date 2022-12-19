```
/* 这道题可以形象的想象成分发标有R和L的牌，一旦左右两边牌数相同就计数+1*/
int balancedStringSplit(char * s){
    int res = 0;
    int len = strlen(s);
    int r = 0, l = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'R') ++r; 
        if (s[i] == 'L') ++l;
        if (r == l) ++res;
    }
    return res;
}
```
