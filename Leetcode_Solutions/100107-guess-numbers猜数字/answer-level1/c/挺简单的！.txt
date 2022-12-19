### 解题思路
此处撰写解题思路

### 代码

```c
int game(int* guess, int guessSize, int* answer, int answerSize){
    int i,ret=0;
    for(i=0;i<guessSize;i++)
    {
        if(guess[i]==answer[i])
        {
            ret++;
        }
    }
    return ret;
}
```