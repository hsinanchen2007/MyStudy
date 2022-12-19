### 解题思路
此处撰写解题思路
1、把num转换为字符串
2、对转换后的字符串按照降序进行排序qsort
3、比较排序前后的差异
4、从后往前找到与排序后比较不一样的字符，
5、交换字符，输出结果
![image.png](https://pic.leetcode-cn.com/d2b87304d1ca80b7301db24a3c5fbc091a1769aa92a9f581757f95c82b6159a1-image.png)


### 代码

```c
static void itoa(int n, char *s)
{
    int i, j;
    char ss[10] = {0};
    i = 0;
    do {
        ss[i++] = n % 10 + '0'; // 取下一个数字
    } while ((n /= 10) > 0);   // 删除该数字
    
    ss[i] = '\0';
    int index = 0;
    for (j = i - 1; j >= 0; j--) { // 生成的数字是逆序的，所以要逆序输出
        s[index++] = ss[j];
        printf("%c", ss[j]);
    }
    s[index] = '\0';
}

static int cmp(const void *a, const void *b)
{
    return *(char *)b - *(char *)a;
}

int maximumSwap(int num)
{
    char s[10] = {0};
    char t[10] = {0};
    itoa(num, s);    
    itoa(num, t);
    int sLen = strlen(s);
    qsort(t, sLen, sizeof(char), cmp);
    if (atoi(s) == atoi(t)) {
        return num;
    }
    int i;
    for (i = 0; i < sLen; i++) {
        if (s[i] == t[i]) {
            continue;
        }
        break;
    }

    int j = 0;
    for (j = sLen; j >= 0; j--) {
        if (s[j] == t[i]) {
            break;
        }
    }
    char tmp = s[i];
    s[i] = t[i];
    s[j] = tmp;
    
    return atoi(s);
}
```