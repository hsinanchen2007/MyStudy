### 简单利用，双100%
利用指针
### 代码

```c
int game(int* guess, int guessSize, int* answer, int answerSize){
    int sum=0;
    while(guessSize--)
       sum += (*guess++ == *answer++)?1:0;
       return sum;
}
```