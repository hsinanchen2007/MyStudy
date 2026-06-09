int romanToInt(char *s) {
    int sum = 0;
    char *p = s;
    int len = strlen(s);
    if (len == 0) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        //xl,xc,x
        if (p[i] == 'X') {
            if (p[i + 1] == 'L') {
                sum += 40;
                i++;
                continue;
            } else if (p[i + 1] == 'C') {
                sum += 90;
                i++;
                continue;
            } else {
                sum += 10;
            }
        }

        //cd,cm,c
        if (p[i] == 'C') {
            if (p[i + 1] == 'D') {
                sum += 400;
                i++;
                continue;
            }
            else if (p[i + 1] == 'M') {
                sum += 900;
                i++;
                continue;
            } else {
                sum += 100;
            }
        }

        //iv,ix,i
        if (p[i] == 'I') {
            if (p[i + 1] == 'V') {
                sum += 4;
                i++;
                continue;
            } else if (p[i + 1] == 'X') {
                sum += 9;
                i++;
                continue;
            } else {
                sum += 1;
            }
        }

        //其他
        if (p[i] == 'V') {
            sum += 5;
        }
        if (p[i] == 'L') {
            sum += 50;
        }
        if (p[i] == 'D') {
            sum += 500;
        }
        if (p[i] == 'M') {
            sum += 1000;
        }
    }

    return
            sum;

}