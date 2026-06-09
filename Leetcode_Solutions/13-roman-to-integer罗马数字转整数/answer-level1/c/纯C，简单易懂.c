### 解题思路
I,X,C在题中的相应字母左边时，相当于-1，-10，-100

### 代码

```c
int romanToInt(char * s){
    int result=0;
    int i=0;
    while(s[i]!='\0'){
        switch(s[i]){
            case 'I':
                if(s[i+1]=='V'||s[i+1]=='X') result-=1;
                else result+=1;
                i++;
                break;
            case 'V':
                result+=5;i++;
                break;
            case 'X':
                if(s[i+1]=='L'||s[i+1]=='C') result-=10;
                else result+=10;
                i++;
                break;
            case 'L':
                result+=50;i++;
                break;
            case 'C':
                if(s[i+1]=='D'||s[i+1]=='M') result-=100;
                else result+=100;
                i++;
                break;
            case 'D':
                result+=500;i++;
                break;
            case 'M':
                result+=1000;i++;
                break;
        }
    }
    return result;
}
```