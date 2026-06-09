### 解题思路
此处撰写解题思路

### 代码

```c
int romanToInt(char * s){
    int sum = 0;
    int cur;
    int i = 0;

    if (s == NULL) {
        return 0;
    }

    while (s[i] != '\0') {
        switch (s[i]) {
            case 'I':{
                if (s[i+1] == 'V') {
                    cur = 4;
                    i = i + 2;
                } else if (s[i+1] == 'X') {
                    cur = 9;
                    i = i + 2;
                } else {
                    cur = 1;
                    i++;
                    while (s[i] == 'I') {
                        cur += 1;
                        i++;
                    }
                }
                break;
            }
            case 'V':{
                cur = 5;
                i++;
                break;
            }
            case 'X':{
                if (s[i+1] == 'L') {
                    cur = 40;
                    i = i + 2;
                } else if (s[i+1] == 'C') {
                    cur = 90;
                    i = i + 2;
                } else {
                    cur = 10;
                    i++;
                    while (s[i] == 'X') {
                        cur += 10;
                        i++;
                    }
                }
                break;
            }
            case 'L':{
                cur = 50;
                i++;
                break;
            }
            case 'C':{
                if (s[i+1] == 'D') {
                    cur = 400;
                    i = i + 2;
                } else if (s[i+1] == 'M') {
                    cur = 900;
                    i = i + 2;
                } else {
                    cur = 100;
                    i++;
                    while (s[i] == 'C') {
                        cur += 100;
                        i++;
                    }
                }
                break;
            }
            case 'D':{
                cur = 500;
                i++;
                break;
            }
            case 'M':{
                cur = 1000;
                i++;
                break;
            }
            default: {
                i++;
                break;
            }
        }
        sum += cur;
    }

    return sum;
}
```