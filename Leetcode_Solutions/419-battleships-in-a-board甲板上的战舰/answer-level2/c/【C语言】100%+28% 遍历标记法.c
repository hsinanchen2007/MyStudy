### 解题思路
1.思路比较简单：
（1）双重循环遍历二维数组。
（2）对于board[i][j] == 'X'的元素，根据题目所给的条件，战舰要么在一列中，要么在一行中，因此试着按一行和按一列遍历同一艘战舰中的元素。对于同一艘战舰中的元素，被遍历过的，从原来的‘X’标为‘B’。
（3）由于同一艘战舰中的元素都被标为‘B’，因此只要发现board[i][j] == 'X'，说明发现了新战舰的一个元素。此时可以对战舰总数ret做++计数。
2.corner condition：
无；
3.知识点总结：
大写字母‘X’的ASICII码是88。
4.耗时：60mins，花的时间太长了，哎~~。主要耗时点：
最开始的时候，算法是将发现的每一艘战舰按发现顺序进行编号，并且战舰中所有的元素都标为该战舰的编号。例如第20艘战舰由3各元素组成，那么第2艘战舰所有的3个元素都从原来的‘X’标为‘20’。这就导致一个问题：‘X’的ASCII码刚好是88，那么在标第88艘战舰时，程序在判断时，会将标为88的元素误认为时‘X’导致将其网89上标。因此，当甲板上的战舰数量大于88时，如果用编号的方式来标，就会导致战舰数量的统计结果多出一艘。这个算法让自己多耗了30mins去排查，第25个用例的错误结果，很不划算。后来才改为将标号固定为‘B’。（其实也可以是其他标号，只要不是‘X’就行）--------边界条件和算法没有在编码之前思考清楚。
5.吐槽：
这个题目真的是要吐槽一下，第一次看题根本不知道是说连在一起的时一艘战舰。题意相当晦涩~~~，不是一个好题。开始还以为是翻译不好，后来看了英文原版的题目，也是一样。

![image.png](https://pic.leetcode-cn.com/1836bfb83e5bccd401e685d4af46f665d982a14c4d9d65884f8f0ce13cf34f1a-image.png)


### 代码

```c

int countBattleships(char** board, int boardSize, int* boardColSize){
    int ret = 0;
    int i = 0;
    int j = 0;
    int m = 0;
    int n = 0;
    for(i = 0; i < boardSize; i++) {
        for(j = 0; j < *boardColSize; j++) {
            if(board[i][j] == 'X') {
                ret++;
                board[i][j] = 'B';
                m = j + 1;
                while(m < *boardColSize && board[i][m] == 'X' ) {
                    board[i][m] = 'B';
                    m++;
                } 
                 n = i + 1;
                 while( n < boardSize && board[n][j] == 'X') {
                     board[n][j] = 'B';
                     n++;
                }
            }
        }
    }
#if 0
    for(i = 0; i < boardSize; i++) {
        for(j = 0; j < *boardColSize; j++) {
            if(board[i][j] == '.') {
                printf(".");
            }
            else {
                printf("%d",board[i][j]);
            }
        }
        printf("\n");
    }
#endif
    return ret;

}
```