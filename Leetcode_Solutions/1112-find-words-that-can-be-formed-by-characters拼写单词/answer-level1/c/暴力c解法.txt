### 解题思路
用数组记录words和chars中每个字母出现的次数，然后比较是否满足chars 中的次数大于等于 words中的次数。

### 代码

```c
//暴力的思路：统计每个单词中的字母的个数，然后在char字符串中看，是否有大于等于字母个数的字符，若无则判断下一个
int countCharacters(char ** words, int wordsSize, char * chars){
    int arr_c[26] = {0};
    int len_c = strlen(chars);
    for(int i=0; i<len_c; ++i)
    {
        arr_c[chars[i]-'a']++;
    }
    int result = 0;
    for(int i=0; i<wordsSize; ++i)
    {
        int len_w = strlen(words[i]);
        int flag = 1;
        int arr_w[26] = {0};
        for(int j=0; j<len_w; ++j)
        {
            arr_w[words[i][j] - 'a']++;
            if(arr_w[words[i][j]-'a'] > arr_c[words[i][j]-'a']){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            result += len_w;
        }
    }
    return result;
}
```