我哭了，你呢？


func gameOfLife(board [][]int)  {

    //2: 马上就要死了，但是他还活着
    //3: 死的，马上活了

    for i:=0; i<len(board);i++ {
        for j:=0; j<len(board[0]); j++ {
            live := 0
            
            if i==0 && j==0{                                 //判断边角
                if len(board[0]) > j+1 && (board[i][j+1] == 2||board[i][j+1] == 1){
                    live++
                }
                if len(board) > i+1 && (board[i+1][j] == 2||board[i+1][j] == 1){
                    live++
                }
                if len(board[0]) > j+1 && len(board) > i+1 && (board[i+1][j+1] == 2||board[i+1][j+1] == 1){
                    live++
                }

            }else if i==0 && j==len(board[0])-1 {
                if j-1>=0  && (board[i][j-1] == 2 ||board[i][j-1] == 1){
                    live++
                }
                if len(board) > i+1 && (board[i+1][j] == 2 ||board[i+1][j] == 1){
                    live++
                }
                if j-1>=0 && len(board) > i+1 && (board[i+1][j-1] == 2||board[i+1][j-1] == 1){
                    live++
                }
            }else if i==len(board)-1 && j==0 {
                if len(board[0]) > j+1 && (board[i][j+1] == 2||board[i][j+1] == 1){
                    live++
                }
                if i-1>=0 && (board[i-1][j] == 2||board[i-1][j] == 1){
                    live++
                }
                if len(board[0]) > j+1 && i-1>=0 && (board[i-1][j+1] == 2||board[i-1][j+1] == 1){
                    live++
                }
            }else if i==len(board)-1 && j==len(board[0])-1{
                if j-1>=0 && (board[i][j -1] == 2||board[i][j-1] == 1){
                    live++
                }
                if i-1>=0 && (board[i-1][j] == 2||board[i-1][j] == 1){
                    live++
                }
                if i-1>=0 && j-1>=0 && (board[i-1][j-1] == 2||board[i-1][j-1] == 1){
                    live++
                }
            }else if i==0{                                   //判断边线
                if j-1>=0 &&  (board[i][j-1] == 2||board[i][j-1] == 1){
                    live++
                }
                if j-1>=0 && len(board) > i+1 &&  (board[i+1][j-1] == 2||board[i+1][j-1] == 1){
                    live++
                }
                if len(board) > i+1 && (board[i+1][j] == 2||board[i+1][j] == 1){
                    live++
                }
                if len(board) > i+1 && len(board[0])>j+1 && (board[i+1][j+1] == 2||board[i+1][j+1] == 1){
                    live++
                }
                if len(board[0])>j+1 && (board[i][j+1] == 2||board[i][j+1] == 1){
                    live++
                }
            }else if i==len(board)-1 {
                if j-1>=0 && (board[i][j-1] == 2||board[i][j-1] == 1){
                    live++
                }
                if j-1>=0 && i-1>=0 && (board[i-1][j-1] == 2||board[i-1][j-1] == 1){
                    live++
                }
                if i-1>=0 && (board[i-1][j] == 2||board[i-1][j] == 1){
                    live++
                }
                if i-1>=0 && len(board[0]) > j+1 && (board[i-1][j+1] == 2||board[i-1][j+1] == 1){
                    live++
                }
                if len(board[0]) > j+1 && (board[i][j+1] == 2||board[i][j+1] == 1){
                    live++
                }
            }else if j==0{
                if  i-1>=0  && (board[i-1][j] == 2||board[i-1][j] == 1){
                    live++
                }
                if i-1>=0  && len(board[0]) > j+1 && (board[i-1][j+1] == 2||board[i-1][j+1] == 1){
                    live++
                }
                if len(board[0]) > j+1 && (board[i][j+1] == 2||board[i][j+1] == 1){
                    live++
                }
                if len(board[0]) > j+1 && len(board) > i+1 && (board[i+1][j+1] == 2||board[i+1][j+1] == 1){
                    live++
                }
                if len(board) > i+1 && (board[i+1][j] == 2||board[i+1][j] == 1){
                    live++
                }
            }else if j==len(board[0])-1 {
                if i-1>=0 && (board[i-1][j] == 2||board[i-1][j] == 1){
                    live++
                }
                if j-1>=0 && i-1>=0 &&(board[i-1][j-1] == 2||board[i-1][j-1] == 1){
                    live++
                }
                if j-1>=0 && (board[i][j-1] == 2||board[i][j-1] == 1){
                    live++
                }
                if j-1>=0 && len(board) > i+1 && (board[i+1][j-1] == 2||board[i+1][j-1] == 1){
                    live++
                }
                if len(board) > i+1 && (board[i+1][j] == 2||board[i+1][j] == 1){
                    live++
                }
            }else {                                         //中间的点
                if j-1>=0 && i-1>=0 && (board[i-1][j-1] == 2||board[i-1][j-1] == 1){
                    live++
                }
                if i-1>=0 && (board[i-1][j] == 2||board[i-1][j] == 1){
                    live++
                }
                if i-1>=0 && len(board[0]) > j+1 && (board[i-1][j+1] == 2||board[i-1][j+1] == 1){
                    live++
                }
                if len(board[0]) > j+1 && (board[i][j+1] == 2||board[i][j+1] == 1){
                    live++
                }
                if len(board) > i+1 && len(board[0]) > j+1 && (board[i+1][j+1] == 2||board[i+1][j+1] == 1){
                    live++
                }
                if len(board) > i+1 && (board[i+1][j] == 2||board[i+1][j] == 1){
                    live++
                }
                if j-1>=0 && (len(board) > i+1 && board[i+1][j-1] == 2||board[i+1][j-1] == 1){
                    live++
                }
                if j-1>=0 && (board[i][j-1] == 2||board[i][j-1] == 1){
                    live++
                }
                
            }

            if live < 2 && board[i][j]==1 {
                board[i][j] = 2
            }else if (live==2||live==3) && board[i][j]==1 {
                board[i][j] = 1
            }else if live > 3 && board[i][j]==1{
                board[i][j] = 2
            }else if live==3 && board[i][j]==0{
                board[i][j] = 3
            }
        }
    }
    for i:=0; i<len(board);i++ {
        for j:=0; j<len(board[0]); j++ {
            if board[i][j] == 2{
                board[i][j] = 0
            }
            if board[i][j] == 3{
                board[i][j] = 1
            }
        }
    }

}