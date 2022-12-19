### 解题思路
先进行判断，若前一个大于后一个则+，后一个大于前一个则-；遇到后者的情况，就把前一个字符换成另一个字符代到case中作为另一种情况。

### 代码

```c
int romanToInt(char * s){
    int count=0,i;
    for(i=0;*(s+i)!='\0';i++){
        if(*(s+i)=='I'&&*(s+i+1)=='V'||*(s+i)=='I'&&*(s+i+1)=='X'||*(s+i)=='X'&&*(s+i+1)=='L'||*(s+i)=='X'&&*(s+i+1)=='C'||*(s+i)=='C'&&*(s+i+1)=='D'||*(s+i)=='C'&&*(s+i+1)=='M'){
            *(s+i)=*(s+i)-1;
        }
        switch (*(s+i)){
            case 'I':
                count+=1;
                break;
            case 'H':
                count-=1;
                break;
            case 'V':
                count+=5;
                break;
            case 'X':
                count+=10;
                break;
            case 'W':
                count-=10;
                break;
            case 'L':
                count+=50;
                break;
            case 'C':
                count+=100;
                break;
            case 'B':
                count-=100;
                break;
            case 'D':
                count+=500;
                break;
            case 'M':
                count+=1000;
                break;
        }
    }
    return count;
}
```