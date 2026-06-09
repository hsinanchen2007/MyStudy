当出现两个字符数量相等，此时则可以分割出子字符串
``` c
int balancedStringSplit(char * s){
    int L_num=0, R_num=0, RL_num=0;
    int i=0;
    while(s[i] != '\0')
    {
        if(s[i] == 'R')
        {
            L_num++;
        }
        else
        {
            R_num++;
        }
        
        if(L_num == R_num)  // 当出现两个字符数量相等，此时则可以分割出子字符串
        {
            RL_num++; 
            L_num = 0;
            R_num = 0;
        }
        
        i++;
    }
    
    return RL_num;
}
```
