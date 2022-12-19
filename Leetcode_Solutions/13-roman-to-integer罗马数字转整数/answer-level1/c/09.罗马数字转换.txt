### 解题思路
这次改写成了指针的形式

### 代码

```c
int romanToInt(char *s){
    int result = 0;
    while(*s)
    {
        switch(*s)
        {
            case 'I' : result += 1; if(*(s+1) == 'V'||*(s+1) == 'X') result -= 2; 
                      break;
            case 'V' : result += 5; break; 
            case 'X' : if(*(s+1) == 'L'||*(s+1) == 'C') result -= 20; 
                        result += 10; break;      
            case 'L' : result += 50; break;
            case 'C' : if(*(s+1) == 'D'||*(s+1) == 'M') result -= 200; 
                        result += 100; break;
            case 'D' : result += 500; break;
            case 'M' : result += 1000; break;
            default : break;
        }
        s++;
    }
    return result;
}
```