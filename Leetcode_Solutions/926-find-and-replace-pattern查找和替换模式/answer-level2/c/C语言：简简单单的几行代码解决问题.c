![QQ截图20190718090435.png](https://pic.leetcode-cn.com/c35189076e74658a4b34524e577e37ecd0feaeabb8b36b8831476556c0624956-QQ%E6%88%AA%E5%9B%BE20190718090435.png)

- 由于字符串中相等的字符存在关联，那么就用一个数组来存放上一个相同字符的的下标，最后和pattern比较就可以了
- 就如下面的情况

![QQ截图20190718091702.png](https://pic.leetcode-cn.com/3814d755d31e95daa073b4d93daef81d0aa604e09ad6718d44c2ab5abc65c14f-QQ%E6%88%AA%E5%9B%BE20190718091702.png)

```
int char_value[128];
int pattern_value[32];
int tmp_value[32];
char ** findAndReplacePattern(char ** words, int wordsSize, char * pattern, int* returnSize){
    char **ret_string = (char **)malloc(64 * sizeof(char *));
    int ret_str_top = 0;
    int str_len = strlen(pattern);  //上面为初始化
    record_index(pattern_value, pattern);   //求出pattern的索引对应的数组
    
    for (int i = 0; i < wordsSize; ++i) {
        record_index(tmp_value, words[i]);  //求出words[i]的索引对应的数组
        if (compare(tmp_value, pattern_value, str_len)) {  //比较
            ret_string[ret_str_top] = (char *)malloc(32);
            ret_string[ret_str_top][0] = 0;
            strcpy(ret_string[ret_str_top], words[i]);
            ++ret_str_top;
        }
    }

    * returnSize = ret_str_top;
    return ret_string;
}
//用来求出每个字符串的索引
void record_index(int *array, char *str)
{
    for (int i = 97; i < 123; ++i) char_value[i] = -1;
    
    for (int i = 0; str[i]; ++i) {
        array[i] = char_value[str[i]];//赋前一个个下标的值
        char_value[str[i]] = i;       //存储当前下标的值
    }
}
//比较两个数组是否相等
int compare(int *arr1, int *arr2, int len)
{
    for (int i = 0; i < len; ++i) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}
```
