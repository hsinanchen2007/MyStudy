### 解法

```java
public int numRookCaptures(char[][] board) {
        int Rx = 0, Ry = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++)
                if(board[i][j] == 'R'){
                    Rx = i;
                    Ry = j;
                    break;
                }
        }
        int count = 0;
        for(int i = Rx + 1; i < 8; i++){
            if(board[i][Ry] == 'B')
                break;
            if(board[i][Ry] == 'p'){
                count++;
                break;
            }
        }
        for(int i = Rx - 1; i >= 0; i--){
            if(board[i][Ry] == 'B')
                break;
            if(board[i][Ry] == 'p'){
                count++;
                break;
            }
        }
        for(int i = Ry + 1; i < 8; i++){
            if(board[Rx][i] == 'B')
                break;
            if(board[Rx][i] == 'p'){
                count++;
                break;
            }
        }
        for(int i = Ry - 1; i >= 0; i--){
            if(board[Rx][i] == 'B')
                break;
            if(board[Rx][i] == 'p'){
                count++;
                break;
            }
        }
        return count;
    }
```

思路分析：

* 题目啰嗦一大堆，翻译一下就是：从某个指定点往上下左右走，遇到障碍物`B`就在该方向停止，遇到第一个`p`计数加1，然后在该方向停止。
* 所以我们只需要第一次遍历得到指定点`R`的索引，然后分别往上下左右，进行四次不同方向的遍历，来统计能在障碍物之前遇到几次`p`。遇到`B`与`p`都要立即停止。
* 主要数组不要越界即可。
* 时间复杂度为常数次，毕竟棋盘大小都限制了；空间复杂度为$O(1)$。

运行结果：

* 执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
* 内存消耗 :37.3 MB, 在所有 Java 提交中击败了5.13%的用户

更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖