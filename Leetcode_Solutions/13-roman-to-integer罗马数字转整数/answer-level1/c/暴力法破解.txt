### 解题思路
暴力法

### 代码

```c
int romanToInt(char * s){
    int i = 0;
    int num;
    int I = 0, V = 0, X = 0, L = 0, C = 0, D = 0, M =0;
    for(;s[i];i++)
    {
        if(s[i] == 'I' &&s[i+1] != 'V' && s[i+1] != 'X')
        {
            I++;
        }
        else if(s[i] == 'I' && s[i+1] == 'V')
        {
            I = I + 4;
            i++;
        }
        else if(s[i] == 'I' && s[i+1] == 'X')
        {
            I = I + 9;
            i++;
        }
        else if (s[i] == 'V')
        {
            V = V + 5;
        }
        else if (s[i] == 'X' && s[i+1] != 'L' && s[i+1] != 'C')
        {
            X = X + 10;
        }
        else if (s[i] == 'X' && s[i+1] == 'L')
        {
            X = X + 40;
            i++;
        }
        else if (s[i] == 'X' && s[i+1] == 'C')
        {
            X = X + 90;
            i++;
        }
        else if (s[i] == 'L')
        {
            L = L + 50;
        }
         else if (s[i] == 'C' && s[i+1] != 'D' && s[i+1] != 'M')
        {
            C = C + 100;
        }
         else if (s[i] == 'C' && s[i+1] == 'D')
        {
            C = C + 400;
            i++;
        }
        else if (s[i] == 'C' && s[i+1] == 'M')
        {
            C = C + 900;
            i++;
        }
        else if (s[i] == 'D')
        {
            L = L + 500;
        }
        else if (s[i] == 'M')
        {
            L = L + 1000;
        }

    }
    num = I+V+X+L+C+D+M;
    return num;
    
}
```