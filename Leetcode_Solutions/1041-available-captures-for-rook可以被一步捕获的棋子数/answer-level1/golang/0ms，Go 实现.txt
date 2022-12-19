
![image.png](https://pic.leetcode-cn.com/1a7e89ae47f991f1344145bdde54d5db7048a3bf6a4ee802dd735c138d39d18c-image.png)

先找到车的位置，然后分别去找上下左右四个方向，直到遇到卒就计数+1，然后退出这个方向的寻找，遇到象直接退出这个方向的寻找。最后返回计数。

代码
```
func numRookCaptures(board [][]byte) int {
    var startx,starty int
    ans := 0
    // 先找到车在那里
    FINDSTART:
    for i:=0; i<8; i++ {
        for j:=0; j<8; j++ {
            if board[i][j] == 'R' {
                startx,starty = i,j
                break FINDSTART
            }
        }
    }
    // 往右边找
    RIGHT:
    for y:=starty+1; y<8; y++ {
        switch board[startx][y] {
            case 'p':ans++;break RIGHT
            case 'B':break RIGHT
        }
    }
    // 往左边找
    LEFT:
    for y:=starty-1; y>=0; y-- {
        switch board[startx][y] {
            case 'p':ans++;break LEFT
            case 'B':break LEFT
        }
    }
    // 往下边找
    DOWN:
    for x:=startx+1; x<8; x++ {
        switch board[x][starty] {
            case 'p':ans++;break DOWN
            case 'B':break DOWN
        }
    }
    // 往上边找
    UP:
    for x:=startx-1; x>=0; x-- {
        switch board[x][starty] {
            case 'p':ans++;break UP
            case 'B':break UP
        }
    }
    return ans
}
```