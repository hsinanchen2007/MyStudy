### 解题思路
1. 每个单词中间加空格组成String；
2. string放入屏幕中看你能够放多少，注意结尾为空格说明还可以继续放入空格，start++;
3. 结尾为非空格需要找到之前第一个空格的位置。

### 代码

```c
int wordsTyping(char ** sentence, int sentenceSize, int rows, int cols){
    /* 组成String再往里面放,每个string中间放空格 */
    char *string = malloc(sizeof(char) * 10001);
    int i = 0;
    int len = 0;
    int send = 0;

    for (i = 0; i < sentenceSize; i++) {
        /* 补上空格加入 */
        len = strlen(sentence[i]);
        int j = 0;
        for (j = 0; j < len; j++) {
            string[send++] = sentence[i][j];
        }
        string[send++] = ' ';
    }
    string[send] = '\0';

    /* 预处理完后string放入处理 */
    len = strlen(string);
    int start = 0;

    for (i = 0; i <rows; i++) {
        start += cols;

        /* 说明string空格可以放入屏幕中 ，start ++ */
        if (string[start%len] == ' ') {
            start ++;
            continue;
        }

        /* 中间截断需要找到第一个非空位置 */
        while(start > 0 && string[(start - 1)%len] != ' ') {
            start--;
        }
    }
    free(string);
    return start/len;
} 
```