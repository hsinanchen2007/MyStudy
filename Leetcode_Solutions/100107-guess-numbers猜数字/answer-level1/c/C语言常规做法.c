```c
int game(int* guess, int guessSize, int* answer, int answerSize){
    int i=0,count=0;
    while(i<guessSize)
        if (guess[i]==answer[i++]) count++;
    return count;
}
```
