### 解题思路
![image.png](https://pic.leetcode-cn.com/362f4f17fb990ce0287f21b511c6c541798eb0a1a31a9de5863642adcab4a0d5-image.png)
主要是字符串的操作，和内存分配初始化容易出现问题。这叫什么算法？递归？

### 代码

```c
void dfs(char* digits, int* returnSize, char* s, char** ret, int len, int step)
{   
    printf("\nstep%d", step);
    if (step == len){
        s[len] = '\0'; //记得加字符结束
        memcpy(ret[*returnSize], s, sizeof(char) * (len + 1));
        (*returnSize)++;
        return;
    }

    int temp = digits[step] - '0';
    printf("\ntemp%d", temp);
    int x[4];
    int lens = 3;
    switch (temp) {
        case 2:
            x[0] = 'a';
            x[1] = 'b';
            x[2] = 'c';
            x[3] = 0;
            break;
        case 3:
            x[0] = 'd';
            x[1] = 'e';
            x[2] = 'f';
            x[3] = 0;
            break;
        case 4:
            x[0] = 'g';
            x[1] = 'h';
            x[2] = 'i';
            x[3] = 0;
            break;
        case 5:
            x[0] = 'j';
            x[1] = 'k';
            x[2] = 'l';
            x[3] = 0;
            break;
        case 6:
            x[0] = 'm';
            x[1] = 'n';
            x[2] = 'o';
            x[3] = 0;
            break;
        case 7:
            lens = 4;
            x[0] = 'p';
            x[1] = 'q';
            x[2] = 'r';
            x[3] = 's';
            break;
        case 8:
            x[0] = 't';
            x[1] = 'u';
            x[2] = 'v';
            x[3] = 0;
            break;
        case 9:
            lens = 4;
            x[0] = 'w';
            x[1] = 'x';
            x[2] = 'y';
            x[3] = 'z';
            break;
    }
    
    //(*digits)++;

    for (int i = 0; i < lens; i++) {
        s[step] = x[i];
        printf("\nx%d", s[step]);
        printf("\nx%d", x[i]);
        dfs(digits, returnSize, s, ret, len, step + 1);

    }
    return;
}

int getinit (int len) 
{   int ret = 1;
    for (int i = 0; i < len; i++) {
        ret *= 4;
    }
    return ret;
}


char ** letterCombinations(char * digits, int* returnSize)
{
    * returnSize = 0;
    int len = strlen(digits);
    printf("\nlen%d", len);
    if (len == 0) {
        return NULL;
    }

    char* s = (char*)malloc(sizeof(char) * (len + 1));
    int initsize = getinit(len);
    char** ret = (char**)malloc(sizeof(char*) * initsize);

    for(int i = 0; i < initsize; i++) {
        ret[i] = (char*)malloc(sizeof(char) * (len + 1));
    }

    dfs(digits, returnSize, s, ret, len, 0);

    return ret;
}
```