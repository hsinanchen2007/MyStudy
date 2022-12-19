### 解题思路
该题解题思路
在‘R’的移动一次范围内 能吃到‘p’的次数

首先便利数组确定目标'R'的坐标[i][j]

为便于叙述下文以i定义为横坐标，j定义为纵坐标说明“
其次要考虑 相同横坐标和纵坐标下是否存在目标‘p’

加了4个for循环 分别控制遍历当前节点 上下左右四个方向
为避免出现越界问题 在循环内部先判断是否越界

当这一步完成了其实大部分都完成了 我们只需新增细化规则问题
当我在以‘R’为初始节点分别向四个方向遍历的过程中，
存在当我查询到’p‘的先后问题，如果我先于‘p’查询到’B‘ 
那么就应该跳出当前循环并断定这一方向有‘p’阻断，以致我无法到达‘p’

如果我直接判断到‘p’ ， 那么就该计数。

![图片.png](https://pic.leetcode-cn.com/f4b5ef299e4604f83f5c703e6cb256eaf4a59846fb2c58bae9aabc90d77c1ccc-%E5%9B%BE%E7%89%87.png)

### 代码

```golang
func numRookCaptures(board [][]byte) int {
    count := 0
    for i := 0 ; i <len(board) ; i++ {
        for j := 0 ; j < len(board[i]); j++ {
            if board[i][j] == 'R' {
                
                for h := j+1; h <len(board[i]); h ++ {
                    if h > 8 {
                        break
                    } else if  board[i][h] == 'B' {
                        break
                    } else if board[i][h] == 'p'{
                        count++
                        break 
                    }
                }

                for h := j-1 ; h > 0; h -- {
                    if h < 0 {
                        break 
                    } else if board[i][h] == 'B' {
                        break 
                    } else if board[i][h] == 'p'{
                        count++
                        break
                    }
                }

                for h := i + 1 ; h < len(board) ; h ++ {
                    if h > 8 {
                        break
                    } else if  board[h][j] == 'B' {
                        break
                    } else if board[h][j] == 'p'{
                        count++
                        break 
                    }
                }

                for h := i - 1 ; h < len(board) ; h -- {
                    if h < 0 {
                        break 
                    } else if board[h][j] == 'B' {
                        break 
                    } else if board[h][j] == 'p'{
                        count++
                        break
                    }
                }

            }
        }
    }
    return count
}
```