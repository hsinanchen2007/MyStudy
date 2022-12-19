### 解题思路
笨方法

### 代码
C
```c
int judge(char x,char y)
{
    if(x=='I'&&y=='V')
    return 4;
    else if(x=='I'&&y=='X')
    return 9;
    else if(x=='X'&&y=='L')
    return 40;
    else if(x=='X'&&y=='C')
    return 90;
    else if(x=='C'&&y=='D')
    return 400;
    else if(x=='C'&&y=='M')
    return 900;
    else
    return 0;
}
int romanToInt(char * s)
{
    int a,b,c,sum=0;
    for(a=0;a<strlen(s);a++)
    {
        b=0;
        b=judge(s[a],s[a+1]);
        if(b!=0)
        {
            sum+=b;
            a++;
        } 
        else
        switch(s[a])
        {
            case 'I':sum++;break;
            case 'V':sum+=5;break;
            case 'X':sum+=10;break;
            case 'L':sum+=50;break;
            case 'C':sum+=100;break;
            case 'D':sum+=500;break;
            case 'M':sum+=1000;break;
        }
    }
    return sum;
}
```