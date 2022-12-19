直接一个一个判断，然后累加来的，有点暴力，欢迎评论
```
int romanToInt(char * s){
    int num = 0;
    int increment = 1000;

    for (int i =0 ; i < strlen(s); ++i){
        switch(s[i]){
            case 'I':
                ++num;
                increment = 1;
                break;
            case 'V':
                if (increment < 5){
                    num += 5 - (increment << 1);
                }
                else
                    num += 5;
                increment = 5;
                break;
            case 'X':
                if (increment < 5){
                    num += 10 - (increment << 1);
                }
                else
                    num += 10;
                increment = 10;
                break;
            case 'L':
                if (increment < 50){
                    num += 50 - (increment << 1);
                }
                else
                    num += 50;
                increment = 50;
                break;
            case 'C':
                if (increment < 100){
                    num += 100 - (increment << 1);
                }
                else
                    num += 100;
                increment = 100;
                break; 
            case 'D':
                if (increment < 500){
                    num += 500 - (increment << 1);
                }
                else
                    num += 500;
                increment = 500;
                break;
            case 'M':
                if (increment < 1000){
                    num += 1000 - (increment << 1);
                }
                else
                    num += 1000;
                increment = 1000;
                break;
            default:
                printf("wrong input!!\n");
                return -1; 
                break;
        }
    }
    return num;
    
}
```
