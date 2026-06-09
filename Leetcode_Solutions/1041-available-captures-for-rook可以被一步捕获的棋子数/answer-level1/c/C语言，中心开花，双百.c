### 解题思路
![image.png](https://pic.leetcode-cn.com/fe7ae6bade758ec850d598af07647133c85d05986d6c93093ae8dbeaf135f7af-image.png)
又碰到了一道可以中心开花的题，上一次是[5.最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)这道题。

当时的题解：[C语言，一个中心，两个基本点，双百](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/cyu-yan-yi-ge-zhong-xin-liang-ge-ji-ben-dian-shuan/)

当时是向两个方向开花，这次是向四个方向开花，原理都是一样的。

1. 找到车（R）的位置；
2. 向四个方向遍历，找到第一个卒（p）则数量加一，该方向不再遍历；
3. 找到第一个象（B），则直接不再遍历该方向。


### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int i,j,k,sign=0,result=0;
    int s1=0,s2=0,s3=0,s4=0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j]=='R'){
                sign=1;
                break;
            }
        }
        if(sign==1) break;
    }
    for(k=1;k<8;k++){
        if(s1==0&&i-k>=0){
            s1=board[i-k][j]=='B'?1:0;
            if(board[i-k][j]=='p'){
                result++;
                s1=1;
            }
        }
        if(s2==0&&i+k<8){
            s2=board[i+k][j]=='B'?1:0;
            if(board[i+k][j]=='p'){
                result++;
                s2=1;
            }
        }
        if(s3==0&&j-k>=0){
            s3=board[i][j-k]=='B'?1:0;
            if(board[i][j-k]=='p'){
                result++;
                s3=1;
            }
        }
        if(s4==0&&j+k<8){
            s4=board[i][j+k]=='B'?1:0;
            if(board[i][j+k]=='p'){
                result++;
                s4=1;
            }
        }
        if(s1==1&&s2==1&&s3==1&&s4==1) break;
    }
    return result;
}
```