### 解题思路
花了几个小时才弄明白，难顶
### 代码

```golang
// 00 都死  01 变死  10 变活   11 都活
//说明一下几个循环中 & 1 的作用,当i-1,y-1处已经被赋值为2，二进制位10，代表当前是死的，下一个状态是活的，和 1 按位 & 之后得 0，因为当前是死细胞，不计算，所以是最终是加0，对结果无影响，如果是3，二进制为11,按位与得1，活细胞，要计算

func gameOfLife(board [][]int)  {
    for i := range board{
        for j := range board[i]{
            count := 0
            if i - 1 > -1 && j - 1 > -1 {//左上方
                count += board[i-1][j-1] & 1 //这里 & 1的原因是倒数第二位可能有值
            }
            if i - 1 > -1 { //上方
                count += board[i-1][j]  & 1
            }
            if i - 1 > -1 && j + 1 < len(board[i]){ //右上方
                count += board[i-1][j+1] & 1
            }
            if j - 1 > -1{ //左边
                count += board[i][j-1] & 1
            }
            if j + 1 < len(board[i]){ // 右边
                count += board[i][j+1] & 1
            }
            if i + 1 < len(board) && j - 1 > -1{ //左下
                count += board[i+1][j-1] & 1
            }
            if i + 1 < len(board){  // 下方
                count += board[i+1][j] & 1
            }
            if i + 1 < len(board) && j + 1 < len(board[i]){//右下
                count += board[i+1][j+1] & 1
            }
            switch count{
            case 0,1:
                board[i][j] &= 1
            case 2://左移一位，保存下一次的状态，自己与自己进行或运算，也就是保持状态不变，该死死，该活活
                board[i][j] |= board[i][j] << 1
            case 3://和1 进行或运算，只要周围是3个活细胞，不管之前是死是活，下一个状态都是活
                board[i][j] |= 1 << 1
            default:
                board[i][j] &= 1
                
                
            }
        }
    }
    for i := range board{
        for j := range board[i]{
            board[i][j] = (board[i][j] >> 1) & 1
        }
    }
}

```