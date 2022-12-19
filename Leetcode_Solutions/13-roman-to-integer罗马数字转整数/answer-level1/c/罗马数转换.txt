### 解题思路
一个转换函数+遍历罗马数，小数在大数前面则加它的负数

### 代码

```c
int getNum(char c){
    int num=0;
    switch(c){
        case 'I':num=1;break;
        case 'V':num=5;break;
        case 'X':num=10;break;
        case 'L':num=50;break;
        case 'C':num=100;break;
        case 'D':num=500;break;
        case 'M':num=1000;break;
    }
    return num;
}
int romanToInt(char * s){
    int sum = 0;
    while(*s!='\0'){
        int value = getNum(*s);
        sum += getNum(*s++)<getNum(*s)?value*(-1):value;
    }
    return sum;
}
```