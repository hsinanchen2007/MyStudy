### 解题思路
此处撰写解题思路

### 代码

```c
int romanToInt(char * s){
    int i=0,j=1;
    int count=0;
    while(s[i]!='\0'){
        if(s[i]=='I'&&s[j]=='V'){
            count=count+4;
            i=i+2;
            j=j+2;
        }
       else if(s[i]=='I'&&s[j]=='X'){
            count=count+9;
            i=i+2;
            j=j+2;
        }
       else if(s[i]=='X'&&s[j]=='L'){
            count=count+40;
            i=i+2;
            j=i+1;
        }
       else if(s[i]=='X'&&s[j]=='C'){
            count=count+90;
            i=i+2;
            j=i+1;
        }
       else if(s[i]=='C'&&s[j]=='D'){
            count=count+400;
            i=i+2;
            j=i+1;
        }
       else if(s[i]=='C'&&s[j]=='M'){
            count=count+900;
            i=i+2;
            j=i+1;
        }
       else if(s[i]=='I'){
            count=count+1;
            i=i+1;
            j=i+1;
        }
        else if(s[i]=='V'){
            count=count+5;
            i=i+1;
            j=i+1;
        }
       else if(s[i]=='X'){
            count=count+10;
            i=i+1;
            j=i+1;
        }
       else if(s[i]=='L'){
            count=count+50;
            i=i+1;
            j=i+1;
        }
        else if(s[i]=='C'){
            count=count+100;
            i=i+1;
            j=i+1;
        }
       else if(s[i]=='D'){
            count=count+500;
            i=i+1;
            j=i+1;
        }
       else if(s[i]=='M'){
            count=count+1000;
            i=i+1;
            j=i+1;
        }
    }
    return count;
}
```