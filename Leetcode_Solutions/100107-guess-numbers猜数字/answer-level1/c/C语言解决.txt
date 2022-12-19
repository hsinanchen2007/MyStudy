### 解题思路
判断两数组相同索引的值是否相同

### 代码

```c
int game(int* guess, int guessSize, int* answer, int answerSize)
{
    int k = 0;
    for(int i = 0; i<guessSize;i++)
    {
        if(guess[i] == answer[i])
        {
            k++;
        }
    }
    return k;
}
```