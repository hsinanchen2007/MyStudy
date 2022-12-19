### 解题思路
1、题目意思含混不清，到底是chars中的所有字符是否足够 创建 words中的几个字符串，然后统计长度
2、还是说 判断 words中的字符是否在chars中存在
3、每个循环都要拷贝一份原始的chars字符串，那应该就是说比如 words中存在一个单词使用了 3个L，但是chars只有2个L，这种情况就不行
4、题目中给的第二个测试用例，我本地调测，答案都是10，提交答案就是18,

综上所述，该题目属于一道非常之烂的题目，google一堆，也没有人清楚的讲述题意，所有人的答案都是大同小异，不是写不出来代码，是你想坚持正义，结果你的答案不能AC

### 代码

```c
bool isOk(char *src, int hash[])
{
    int i = 0;
    while(src[i] != '\0') {
        if (hash[src[i] - 97] == 0) {
            return false;
        }
        else {
            hash[src[i] - 97]--;
        }
        i++;
    }
    return true; 
}

int countCharacters(char ** words, int wordsSize, char * chars){
    int sum = 0;
    int i = 0;
    int hash[26] = {0};
    int tmp[26] = {0};

    while(chars[i] != '\0') {
        hash[chars[i] - 97]++;
        i++;
    }

    for (i = 0; i < wordsSize; i++) {
        memcpy(tmp, hash, sizeof(int) * 26);
        if (isOk(words[i], tmp)) {
            sum += strlen(words[i]);
        }
    }

    return sum;
}
```