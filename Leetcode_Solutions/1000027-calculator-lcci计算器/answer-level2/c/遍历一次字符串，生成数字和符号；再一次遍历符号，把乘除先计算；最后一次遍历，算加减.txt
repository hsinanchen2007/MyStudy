遍历一次字符串，生成数字和符号；
for (i = 0; i < len; i++) {
        if (s[i] == tmp[4]) {
            continue;
        } else if ((s[i] >= '0') && (s[i] <= '9')) {
            num[numn] = num[numn] * 10 + s[i] - '0';
        }
        for(j = 0; j < 4; j++) {
            if (s[i] == tmp[j]) {
                numn++;
                op[optn++] = j + 1;
                break;
            }
        }
    }
}
其中：op[i]:1、2、3、4分别代表+ - * /

再一次遍历符号，把乘除先计算，然后将乘除的因数改成0，只留其中一个，但需要基于乘除前的符号修改乘除符号：
for (i = 0; i < optn; i++) {
        switch (op[i]) {
            case 3: 
            num[i + 1] = num[i] * num[i + 1];
            num[i] = 0;
            if (i - 1 >= 0) {
                op[i] = op[i - 1];
            } else {
                op[i] = 1;
            }
            break;
            case 4:
            num[i + 1] = num[i] / num[i + 1];
            num[i] = 0;
            if (i - 1 >= 0) {
                op[i] = op[i - 1];
            } else {
                op[i] = 1;
            }
            break;
        }
    }
}

最后一次遍历，算加减
    result = num[0];
    for (i = 0; i < optn; i++) {
        switch (op[i]) {
            case 1: 
            result = result + num[i + 1];
            break;
            case 2:
            result = result - num[i + 1];
            break;
        }
    }





完整代码，没做格式化及函数切分，凑合着看：
int calculate(char* s){
    int len;
    long long result = 0;
    int arr[4][100000] = {0};
    int op[100000] = {0};
    long long num[100001] = {0};
    char tmp[5] = {'+', '-', '*', '/', ' '};
    len = strlen(s);
    int i;
    int j;
    int numn = 0;
    int optn = 0;
    for (i = 0; i < len; i++) {
        if (s[i] == tmp[4]) {
            continue;
        } else if ((s[i] >= '0') && (s[i] <= '9')) {
            num[numn] = num[numn] * 10 + s[i] - '0';
        }
        for(j = 0; j < 4; j++) {
            if (s[i] == tmp[j]) {
                numn++;
                op[optn++] = j + 1;
                break;
            }
        }
    }

    for (i = 0; i < optn; i++) {
        switch (op[i]) {
            case 3: 
            num[i + 1] = num[i] * num[i + 1];
            num[i] = 0;
            if (i - 1 >= 0) {
                op[i] = op[i - 1];
            } else {
                op[i] = 1;
            }
            break;
            case 4:
            num[i + 1] = num[i] / num[i + 1];
            num[i] = 0;
            if (i - 1 >= 0) {
                op[i] = op[i - 1];
            } else {
                op[i] = 1;
            }
            break;
        }
    }
    result = num[0];
    for (i = 0; i < optn; i++) {
        switch (op[i]) {
            case 1: 
            result = result + num[i + 1];
            break;
            case 2:
            result = result - num[i + 1];
            break;
        }
    }

    return (int)result;

}