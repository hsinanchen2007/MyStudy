就再外面套一层0，然后就可以忽略在边缘的数字。
ps：刚开始刷leetcode 确实好用

public void gameOfLife(int[][] board) {
        
        int rows = board.length;
        int cols = board[0].length;
        int[][] cp=new int[rows+2][cols+2];      
        for (int row = 1; row < rows+1; row++) {
            for (int col = 1; col < cols+1; col++) {
                cp[row][col] = board[row-1][col-1]+1;
            }
        }
        int alive;
        for(int j=1;j<cp.length-1;j++){
            for(int i=1;i<(cp[0].length)-1;i++){
                alive=0;
                
                    for(int x=-1; x<2;x++){
                        for(int y=-1;y<2;y++){
                            if(cp[j+x][i+y]==2){
                                alive++;
                            }

                        }
                    }
                    if(cp[j][i]==1){
                        if(alive==3){
                            board[j-1][i-1]=1;
                        }

                    }
                    else if(cp[j][i]==2){
                       
                        if((alive-1)<2 || (alive-1)>3){
                            board[j-1][i-1]=0;
                        }


                    }
                }
            }

          
       }




    
