### 解题思路
精简后的代码

### 代码

```c
int game(int* guess, int guessSize, int* answer, int answerSize){
int cnt=0;
while(guessSize--)
{
    if(*guess++==*answer++)
    cnt++;
}
return cnt;
}
```