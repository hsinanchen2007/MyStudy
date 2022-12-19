先找到车的位置，然后从四个方向里面找p得数量。注意一次只能威胁到一个p，所以即使是有多个p在同一方向上也只算一个，因此遇到B就清0，遇到p就赋值1。最后返回数量的和。双重循环退出是个需要注意的地方。Btw, 第一次双100%，纪念一下。
```
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int count = 0;
        unsigned i=0,j=0;
        bool flag = false;
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(board[i][j]=='R'){ 
                    flag=true;break;
                    }

                
            }
            if(flag)break;
        }
        int left = 0;

        
        for(unsigned k=0;k<j;k++){
            if(board[i][k] =='p') { left=1;}
            else if(board[i][k] == 'B'){
                left = 0;
            }
        }
        int right=0;
        if(j<7){
        for(unsigned k=j+1;k<8;k++){
             if(board[i][k] =='p') { right=1;}
            else if(board[i][k] == 'B'){
                break;
            }
        }
        }
        int up =0;
        for(unsigned k=0;k<i;k++){
            if(board[k][j] =='p') { up=1;}
            else if(board[k][j] == 'B'){
                up = 0;
            }
        }
        int down=0;
        if(i<7){
        for(unsigned k=i+1;k<8;k++){
            if(board[k][j] =='p') { down=1;}
            else if(board[k][j] == 'B'){
                break;
            }
        }}
        
        count = left + right +up +down;
        return count;

    }
};
```
