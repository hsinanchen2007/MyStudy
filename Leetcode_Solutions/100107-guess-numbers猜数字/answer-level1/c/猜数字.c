### 解题思路
因为数组下标也是对应的，所以简单的循环即可解决问题

### 代码

```c
int game(int* guess, int guessSize, int* answer, int answerSize){
    int i = 0;
    int cnt = 0;
    for (i = 0; i < 3; i++) {
        if (guess[i] == answer[i]) {
            cnt++;
        }
    }
    return cnt;
}
```