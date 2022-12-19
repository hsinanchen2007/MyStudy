# 解题思路
 1)先转化为字符串
 2)对字符串从大->小排序
 3)排序前和排序后的字符串 从0->len 比较字符， 找到第一个不一样的字符A/B就是 待交换的字符
 4)在排序前的字符串中，逆序查找该字符 交换A/B即可
 5)字符串再转成数字

# 代码
```
static int cmp(const void *a, const void *b)
{
    return *((char*)b) - *((char*)a);
}

int maximumSwap(int num){
    if (num == 0) {
        return 0;
    }
    char str0[16] = {0};
    char str[16] = {0};

    sprintf(str0, "%d", num);
    sprintf(str, "%d", num);

    int len = (int) strlen(str);

    qsort(str, len, sizeof(char), cmp);
    
    for (int i = 0; i < len; i++) {
        if (str[i] != str0[i]) {
            char *p = strrchr(&str0[i], str[i]);
            *p = str0[i]; 
            str0[i] = str[i];
            break;
        }
    }

    return atoi(str0);
}
```
