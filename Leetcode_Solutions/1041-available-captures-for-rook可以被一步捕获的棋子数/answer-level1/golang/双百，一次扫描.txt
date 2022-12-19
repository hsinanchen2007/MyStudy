### 解题思路
此处撰写解题思路

### 代码

```golang
func numRookCaptures(board [][]byte) int {

    ans := 0
    w:=[8]int{-1,-1,-1,-1,-1,-1,-1,-1}   //横向最底
    for i:=0;i<8;i++{
        h:=-1
        for j:=0;j<8;j++{

            if( string(board[i][j]) == "p"){
                h = 1
                w[j] = 1
            }
            if( string(board[i][j]) == "B"){
                h =-1
                w[j] = -1
            }

            if( string(board[i][j]) == "R"){
                if( w[j] != -1) {
                    ans++
                }
                if( h != -1){
                    ans++
                }

                Loop:
                for jj:=j;jj<8;jj++{
                    if( string(board[i][jj]) == "p"){
                        ans++
                        break Loop
                    }
                    if( string(board[i][jj]) == "B"){
                        break Loop
                    }
                }

                Loop2:
                for ii:=i;ii<8;ii++{
                    if( string(board[ii][j]) == "p"){
                        ans++
                        break Loop2
                    }
                    if( string(board[ii][j]) == "B"){
                        break Loop2
                    }
                }

                return ans
            }

        }
    }

    return ans
}
```