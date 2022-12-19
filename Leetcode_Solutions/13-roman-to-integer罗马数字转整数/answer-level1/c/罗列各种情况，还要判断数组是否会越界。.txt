### 解题思路
此处撰写解题思路

### 代码

```c
int romanToInt(char * s){
    int i = 0;
    int sum = 0;
    int lenth = strlen(s);

    while (i < lenth) {
        //printf("sum = %d\n", sum);
        if (s[i] == 'I') {
            if ( i + 1 < lenth && s[i + 1] == 'V') {
                sum += 4;
                i += 2;
            }
            else if (i + 1 < lenth && s[i + 1] == 'X') {
                sum += 9;
                i += 2;
            }
            else {
                sum += 1;
                i++;
            }
            continue;
        }

        if (s[i] == 'X') {
            if ( i + 1 < lenth && s[i + 1] == 'L') {
                sum += 40;
                i += 2;
            }
            else if ( i + 1 < lenth && s[i + 1] == 'C') {
                sum += 90;
                i += 2;
            }
            else {
                sum += 10;
                i++;
            }
            continue;
        }

        if (s[i] == 'C') {
            if ( i + 1 < lenth && s[i + 1] == 'D') {
                sum += 400;
                i += 2;
            }
            else if ( i + 1 < lenth && s[i + 1] == 'M') {
                sum += 900;
                i += 2;
            }
            else {
                sum += 100;
                i++;
            }
            continue;
        }

        if (s[i] == 'V') {
            sum += 5;
        }

        if (s[i] == 'X') {
            sum += 10;
        }

        if (s[i] == 'L') {
            sum += 50;
        }

        if (s[i] == 'D') {
            sum += 500;
        }

        if (s[i] == 'M') {
            sum += 1000;
        }
        i++;
    }

    return sum;
}
```