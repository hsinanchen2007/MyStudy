```
C语言暴力解法
int romanToInt(char * s){
    int a,i,num;
    num=0;
    a=strlen(s);
    for(i=0;i<a;i++)
    {switch(s[i])
    {  case 'I':
                if(s[i+1]=='V')
                 {num=num+4;
                     i=i+1;
                    break;}
                 if(s[i+1]=='X')
                         {num=num+9;
                             i=i+1;
                             break;}
                  else
                     {num=num+1;
                        break;}
        case 'V':
            num=num+5;
            break;  
        case 'X':
                 if(s[i+1]=='L')
                    {num=num+40;
                        i=i+1;
                        break;}
                 if(s[i+1]=='C')
                     {num=num+90;
                        i=i+1;
                        break; }
                else
                         {num=num+10;
                            break;}
        case 'L':
             num=num+50;
             break;
        case 'C':
                 if(s[i+1]=='D')
                    { num=num+400;
                        i=i+1;
                        break; }
                     if(s[i+1]=='M')
                        {num=num+900;
                            i=i+1;
                            break;}
                 else
                         {num=num+100;
                            break;}
        case 'D':
             num=num+500;
             break;
        case 'M':
             num=num+1000;
             break;

    }}
     
    return num;
}

```
