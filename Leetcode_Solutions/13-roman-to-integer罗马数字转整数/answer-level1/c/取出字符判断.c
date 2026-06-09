### 解题思路
此处撰写解题思路
取出每个字符，如果出现左边的字符比右边的字符小，则转为取两个字符，否则就取一位字符
### 代码

```c
int getOne(char c){
    if(c == 'I')return 1;
    if(c == 'V')return 5;
    if(c == 'X')return 10;
    if(c == 'L')return 50;
    if(c == 'C')return 100;
    if(c == 'D')return 500;
    if(c == 'M')return 1000;

    return 0;
}

int getTwo(char *c){
    if(c[0] == 'I' && c[1] == 'V')return 4;
    if(c[0] == 'I' && c[1] == 'X')return 9;
    if(c[0] == 'X' && c[1] == 'L')return 40;
    if(c[0] == 'X' && c[1] == 'C')return 90;
    if(c[0] == 'C' && c[1] == 'D')return 400;
    if(c[0] == 'C' && c[1] == 'M')return 900;
    return 0;
}

int romanToInt(char * s){
    int sum = 0;

    char *p = s;
    while(*p != 0){
        if(strlen(p) > 1){
            if(getOne(*p) < getOne(*(p + 1))){
                sum += getTwo(p);
                p += 2;
            }else{
                sum += getOne(*p);
                p++;
            }
        }else{
            sum += getOne(*p);
            break;
        }
    }
    return sum;
}


```