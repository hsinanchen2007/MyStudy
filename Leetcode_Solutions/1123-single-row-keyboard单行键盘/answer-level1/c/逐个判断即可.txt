### 解题思路
对于每一个word里面的字符进行判断即可。

### 代码

```c
int calculateTime(char * keyboard, char * word){
    int lew = strlen(word);
    if (strlen(keyboard) != 26 || lew < 1 || lew > 10000) {
        return 0;
    }
    int length = 0, temp = 0;
    for (int i = 0; i < lew; i++) {
        for (int j = 0; j < 26; j++) {
            if (word[i] == keyboard[j]) {
                length += abs(j - temp);
                temp = j;
            }
        }
    }
    return length;
}


```