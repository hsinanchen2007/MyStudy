### 解题思路

小白：
先定义一个有3个元素的数组，用for循环表示数组下标，如果guess[i]等于answer[i],则表示猜对了，计数加一。
（如果思路描述不准确，希望大家可以指出，谢谢）

### 代码

```c
int game(int* guess, int guessSize, int* answer, int answerSize){
    int a[3];
    int i;
    int count=0;
    for(i=0;i<3;i++){
        if(guess[i]==answer[i]){
            count++;
        }

    }
    return count;

}