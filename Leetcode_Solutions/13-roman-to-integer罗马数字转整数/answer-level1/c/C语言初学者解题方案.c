4ms  5.4MB
```
int romanToInt(char * s){
     int Size=strlen(s);
     int i,y=0;
     for(i=0;i<Size;i++)
     {
         switch(s[i])
         {
            case 'I':
               if(s[i+1]=='V'||s[i+1]=='X')y=y-1;
               else y=y+1;break;
            case 'V':
              y=y+5;break;
            case 'X':
              if(s[i+1]=='L'||s[i+1]=='C')y=y-10;
              else y=y+10;break;
            case 'L':
              y=y+50;break;
            case 'C':
              if(s[i+1]=='D'||s[i+1]=='M')y=y-100;
              else y=y+100;break;
            case 'D':
              y=y+500;break;
            case 'M':
              y=y+1000;break;
         }
     }
return y;
}
```
