### 解题思路
8ms 5.4MB
整体思路是从左到右依次判断是哪个字母，
如果不是特殊的字符就直接将其对应的数字加到result中，
然后再向下读一个字符（代码里边是先向下读一个字符再加到result中，不影响），
对于比较特殊的IXC,就判断他们后边的字符是不是那几种，
如果不是就按照上边一个字符的方法处理，
如果是的话就将特殊的两个字符的数值加到result中，
然后向下读两个字符（相当于刚刚一次读了两个字符），
这样依次读到末尾然后返回result的值。

### 代码

```c
int romanToInt(char * s){
    int result = 0;

    while(*s != '\0'){
        switch(*s){
            case 'I':
                if(*(s + 1) == 'V'){
                    s = s +2;
                    result += 4;
                    break;
                }
                else if(*(s + 1) == 'X'){
                    s = s + 2;
                    result += 9;
                    break;
                }
                else{
                    s = s + 1;
                    result += 1;
                    break;
                }
            case 'V':
                s = s + 1;
                result += 5;
                break;
            case 'X':
                if(*(s + 1) == 'L'){
                    s = s + 2;
                    result += 40;
                    break;
                }
                else if(*(s + 1) == 'C'){
                    s = s + 2;
                    result += 90;
                    break;
                }
                else{
                    s = s + 1;
                    result +=10;
                    break;
                }
            case 'L':
                s = s + 1;
                result += 50;
                break;
            case 'C':
                if(*(s + 1) == 'D'){
                    s = s + 2;
                    result += 400;
                    break;
                }
                else if(*(s + 1) == 'M'){
                    s = s + 2;
                    result += 900;
                    break;
                }
                else{
                    s = s + 1;
                    result += 100;
                    break;
                }
            case 'D':
                s = s + 1;
                result += 500;
                break;
            case 'M':
                s = s + 1;
                result += 1000;
                break;
            default:
                break;
        }
    }

    return result;
}
```