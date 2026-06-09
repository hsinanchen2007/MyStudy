### 解题思路
一次遍历解决，不断更新最近路径。
遇到路径为1直接返回，提升效率。

### 代码

```c
int findClosest(char** words, int wordsSize, char* word1, char* word2){
    int ans = 100000;
    int m = -1;
    int n = -1;

    for (int i = 0; i < wordsSize; i++) {
        if (strcmp(words[i], word1) == 0) {
            m = i;   
        } else if (strcmp(words[i], word2) == 0) {
            n = i;
        }
        if ((m != -1) && (n != -1)) {
            ans = (ans < abs(m - n)) ? ans : abs(m - n);
        }

        if (ans == 1) {
            return ans;
        }
    }

    return ans;

}
```