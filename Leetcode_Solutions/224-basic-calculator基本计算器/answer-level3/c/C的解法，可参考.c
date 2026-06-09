### 解题思路
1、遇到空格，跳过；
2、遇到加减，记录一个标记，用来后续做加减运算，继续；
3、遇到（，递归调用，传入下一个的开始位置，传出）的下一个位置和（）括号中的值，和前面的进行计算，把当前的位置拉到）下一个；
4、遇到），传出下一个位置，直接返回结果；
5、遇到数字，循环全部找到，和符号一起做一次计算；

### 代码

```c


int calculateInner(char * s, int* Pos){
    int pos = *Pos;
    char* currentChar = s;
    int result = 0;
    int flag = 1;
    int tempNum = 0;

    while (*(s + pos) != '\0') {
        currentChar = s + pos;

        if (*currentChar == ' ') {
            pos++;
            continue;
        } else if (isdigit(*currentChar)) {
            tempNum = 0;
            while(isdigit(*currentChar)) {
                tempNum = tempNum * 10 + (*currentChar - '0');
                pos++;
                currentChar = s + pos;
            }
            result = result + (flag * tempNum);
            continue;
        } else if (*currentChar == '+') {
            flag = 1;
            pos++;
            continue;
        } else if (*currentChar == '-') {
           // printf("- get flag = %d \n", flag);
            flag = -1;
            pos++;
            continue;
        } else if (*currentChar == '(') {
            *Pos = pos + 1;
            tempNum = calculateInner(s, Pos);
            result = result + (flag * tempNum);
            pos = *Pos;
        } else if (*currentChar == ')') {
            *Pos = pos + 1;
            return result;
        }
    }

    return result;
}

int calculate(char* s)
{
    int pos = 0;
    return calculateInner(s, &pos);
}
```