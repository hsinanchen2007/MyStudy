```
int balancedStringSplit(char * s)
{
    int r = 0, l = 0, sum = 0;
    while(* s)
    {
        if(* s == 'R')
        {
            r += 1;
        }
        else if(* s == 'L')
        {
            l += 1;
        }
        if(r == l)
        {
            sum += 1;
        }
        s += 1;
    }

    return sum;
}
```
