### 解题思路
也不知道为什么leetcode类似题的函数老爱给四个变量。。。。不知道主函数里传进来的anserSize是什么，自己把它再初始化了一下。

### 代码

```c
int game(int* guess, int guessSize, int* answer, int answerSize){
answerSize=0;
for(int i=0;i<3;i++){
    if(answer[i]==guess[i])
    answerSize++;
}
return answerSize;
}
```