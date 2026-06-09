刚刚入门C的小白，目前只会用C中最基础的语法结构做题。



```c
int romanToInt(char * s){
    int i=0,count=0;
    while(s[i]!='\0')
    {
        switch(s[i])
        {
            case 'I':if(s[i+1]=='V')
                    {
                        count+=4;
                        i++;
                    }
                    else if(s[i+1]=='X')
                    {
                        count+=9;
                        i++;
                    }
                    else
                        count+=1;
                    break;
            case 'V':count+=5;break;
            case 'X':if(s[i+1]=='L')
                    {
                        count+=40;
                        i++;
                    }
                    else if(s[i+1]=='C')
                    {
                        count+=90;
                        i++;
                    }
                    else
                        count+=10;
                    break;
            case 'L':count+=50;break;
            case 'C':if(s[i+1]=='D')
                    {
                        count+=400;
                        i++;
                    }
                    else if(s[i+1]=='M')
                    {
                        count+=900;
                        i++;
                    }
                    else
                        count+=100;
                    break;
            case 'D':count+=500;break;
            case 'M':count+=1000;break;
            default:break;
        }
        i++;
    }
    return count;
}
```