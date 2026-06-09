```c
int game(int* guess, int guessSize, int* answer, int answerSize){
    int count=0;
    while(guessSize--)count+=(*guess++==*answer++)?1:0;
    return count;
}
```