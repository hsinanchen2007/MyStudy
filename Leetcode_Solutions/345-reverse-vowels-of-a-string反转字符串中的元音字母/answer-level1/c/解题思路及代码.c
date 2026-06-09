### 解题思路
1、题目未给字符串长度，根据题意，可直接在原字符串上修改，不需额外开辟空间
2、解题策略：双指针轮询，同时找到元音字母反转（字符替换）
3、结束条件：前向指针大于后向指针
4、写子函数完成元音字母查询
5、特殊用例：单字母（元音、辅音、大小写）、多字母单元音、一对元音、多对元音

### 代码

```c
int FindVowels(char *s) {
    int ret;

    ret = 0;

    if ((*s == 'a') || (*s == 'e') || (*s == 'i') || (*s == 'o') || (*s == 'u') ||
        (*s == 'A') || (*s == 'E') || (*s == 'I') || (*s == 'O') || (*s == 'U')) {
        ret = 1;
    }

    return ret;
}

char * reverseVowels(char * s) {
    int i, j;
    char c;
    int flag;

    i = 0;
    j = strlen(s) - 1;
    while (i < j) {
        flag = 0;
        if (1 != FindVowels(&s[i])) {
            i++;            
        }
        else {
            flag++;
        }

        if (1 != FindVowels(&s[j])) {
            j--;
        }
        else {
            flag++;
        }

        if (flag == 2) {
            c = s[j];
            s[j] = s[i];
            s[i] = c;
            i++;
            j--;
        }

    }

    return s;
}
```