### 解题思路
此题比较直接的思路就是先找“车”的位置坐标，然后再分别从“上、下、左、右”分别寻找“卒”和“象”的相对位置即可。
但要注意的是在四周遍历的时候要从四周往“车”的位置上靠拢，这样才能保证你最后记录的“卒”和“象”的位置是离“车”最近的，也就是直接影响结果的。比如： “象” “卒” “卒” “象” “车”这个位置，你如果从右往左遍历的时候，最后记录的“象”的横坐标是小于“卒”的横坐标的，于是根据判定条件你判定此时“车”可以吃到“卒”，但其实是不可以的。

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
           if(board.size()==0)return 0;
           int Rx,Ry,countp=0;
           //找到车的位置坐标
           for(int i=0;i<board.size();i++){
               for(int j=0;j<board[0].size();j++){
                   if(board[i][j]=='R'){
                       Rx=i;
                       Ry=j;
                       break;
                   }
               }
           }
           //上
           if(Rx>0){
           int px1=-1,Bx1=-1;
           for(int i=0;i<Rx;i++){
               if(board[i][Ry]=='p'){
                     px1=i;
               }
               if(board[i][Ry]=='B'){
                   Bx1=i;
               }
           }
           if(px1>Bx1) countp++;
           }
           //下
           if(Rx<board.size()){
           int px2=8,Bx2=8;
           for(int i=board.size()-1;i>Rx;i--){
               if(board[i][Ry]=='p'){
                     px2=i;
               }
               if(board[i][Ry]=='B'){
                   Bx2=i;
               }
           }
           if(px2<Bx2)countp++;}
           //左
           if(Ry>0){
           int py1=-1,By1=-1;
           for(int j=0;j<Ry;j++){
               if(board[Rx][j]=='p'){
                   py1=j;
               }
               if(board[Rx][j]=='B'){
                   By1=j;
               }
           }
           if(py1>By1)countp++;}

           //右
           if(Ry<board[0].size()){
           int py2=8,By2=8;
           for(int j=board[0].size()-1;j>Ry;j--){
               if(board[Rx][j]=='p'){
                   py2=j;
               }
               if(board[Rx][j]=='B'){
                   By2=j;
               }
           }
           if(py2<By2)countp++;}

           return countp;
    }
};
```