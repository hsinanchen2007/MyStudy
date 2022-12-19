### 解题思路
数组是相等的只需要遍历一遍

### 代码

```c
int game(int* guess, int guessSize, int* answer, int answerSize){
    int count=0;
    int i;
    int j;
    for( i=0;i<guessSize;i++)
    {
        if(guess[i]==answer[i])
        {
            count++;
        }

    }
return count;

}
```