int romanToInt(char * s)
{
    int len=strlen(s);
    int t=0,j;


    for(int j=0;j<len;j++)
    {
        switch(s[j])
        {
            case 'I': 
            if(s[j]=='I'&&(s[j+1]=='V'||s[j+1]=='X'))
           { t-=1;break;}
            t+=1;break;
            case 'V': t+=5;break;
            case 'X':
            if(s[j]=='X'&&(s[j+1]=='L'||s[j+1]=='C'))
            { t-=10;break;}
              t+=10;break;
            case 'L': t+=50;break;
            case 'C':
             if(s[j]=='C'&&(s[j+1]=='D'||s[j+1]=='M'))
             {t-=100;break;}
             t+=100;break;
            case 'D': t+=500;break;
            case 'M': t+=1000;break;
            default : break;
        }
    }
    return t;
}

