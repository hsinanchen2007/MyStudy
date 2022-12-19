```
// char *strcat(char *dest, const char *src)
const char roman[4][10][5]={
    {"0","M","MM","MMM",0,0,0,0,0,0,},                    // 千位 1000-3000
    {"0","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",},// 百位 100-900
    {"0","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",},// 十位 10-90
    {"0","I","II","III","IV","V","VI","VII","VIII","IX",} // 个位 1-9
};
char * intToRoman(int num){
    char number[50];
    memset(number,0,50);
    
    if((num<=0)||(num>3999) )
        return NULL;
    
    int carry[4],i=3;
    memset(carry,0,4);
    while(i>=0)// 按顺序键入个位、十位…
    {
        carry[i] = num % 10;
        num /= 10;
        i--;
        
    }
    for(i=0;i<4;i++)
    {
        //printf("%d  ", carry[i]);
        if(0==carry[i]) continue;
        else
            strcat(number,roman[i][carry[i]]);
    }
    char *t=number;
    return t;
}
```
