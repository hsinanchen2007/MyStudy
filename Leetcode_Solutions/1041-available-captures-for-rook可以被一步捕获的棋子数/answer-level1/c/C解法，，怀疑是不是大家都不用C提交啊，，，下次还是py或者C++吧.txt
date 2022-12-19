疑惑。。。。难道没人用C提交嘛
两个100%
就按照题意来做就可以了，先找到rook，再一个方向一个方向来
考虑到效率问题，可以一个循环四个方向一块走，但考虑到超界问题，我还是一个方向一个方向来
题解如下
```
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int ans=0;
    int flag=0;
    int pos_i=0,pos_j=0,pos=0;
    while(flag==0&pos_i<8&pos_j<8){
        if(board[pos_i][pos_j]=='R')
            flag=1;
        else{
            pos++;
            pos_j=pos%boardSize;
            pos_i=pos/boardSize;
        }

    }
    int i=0;
    while(pos_i-i>=0){
        if(board[pos_i-i][pos_j]=='B')
            break;
        else if(board[pos_i-i][pos_j]=='p'){
            ans++;
            break;
        }
        else{
            i++;
        }
    }
    i=0;
    while(pos_i+i<boardSize){
        if(board[pos_i+i][pos_j]=='B')
            break;
        else if(board[pos_i+i][pos_j]=='p'){
            ans++;
            break;
        }
        else{
            i++;
        }
    }
    i=0;
    while(pos_j-i>=0){
        if(board[pos_i][pos_j-i]=='B')
            break;
        else if(board[pos_i][pos_j-i]=='p'){
            ans++;
            break;
        }
        else{
            i++;
        }
    }
    i=0;
    while(pos_j+i<boardSize){
        if(board[pos_i][pos_j+i]=='B')
            break;
        else if(board[pos_i][pos_j+i]=='p'){
            ans++;
            break;
        }
        else{
            i++;
        }
    }
    return ans;
}
```
