### 解题思路
逐一比较。

### 代码

```c
int game(int* guess, int guessSize, int* answer, int answerSize){
    guessSize=answerSize;
    int sum=0;
    for(int i=0;i<guessSize;i++){
        if(guess[i]==answer[i])
        sum++;
    }
    return sum;
}
```