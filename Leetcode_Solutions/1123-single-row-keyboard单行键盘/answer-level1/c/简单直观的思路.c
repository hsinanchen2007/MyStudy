### 解题思路

### 代码

```c
int calculateTime(char * keyboard, char * word){
    int i;
    int j;
    int sum = 0;
    int idx = 0;
    int wLen = strlen(word);
    int kLen = strlen(keyboard);

    for (i = 0; i < wLen; i++) {
        for (j = 0; j < kLen; j++) {
            if (word[i] == keyboard[j]) {
                sum += abs(idx - j);
                idx = j;
                break;
            }
        }
    }
    return sum;
}
```