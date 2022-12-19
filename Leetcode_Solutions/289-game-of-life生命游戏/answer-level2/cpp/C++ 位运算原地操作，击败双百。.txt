一个 int 有 32 bit，输入数据只用了一个 bit，所以我们可以利用其他空闲的bit位进行“原地修改”。
具体的位运算操作可以查看代码注释。
```
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        int dy[] = {-1, -1, -1,  0, 0,  1, 1, 1};

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0 ; j < board[0].size(); j++) {
                int sum = 0;
                for(int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                        sum += (board[nx][ny]&1); // 只累加最低位
                    }
                }
                if(board[i][j] == 1) {
                    if(sum == 2 || sum == 3) {
                        board[i][j] |= 2;  // 使用第二个bit标记是否存活
                    }
                } else {
                    if(sum == 3) {
                        board[i][j] |= 2; // 使用第二个bit标记是否存活
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                board[i][j] >>= 1; //右移一位，用第二bit覆盖第一个bit。
            }
        }
    }
};
```
![image.png](https://pic.leetcode-cn.com/51c4e14d9aba3776396540971ddfd060d8737d2bfac97353bf4361a1d11913f7-image.png)

**如果感觉有点意思，加个反手一个赞吧~**

太不可思议了，竟然还挂在第一个。。。
分享一下自己的公众号👏HelloNebula👏 ，感兴趣的小伙伴可以关注一下。
![qrcode_for_gh_6e5f8557b1f8_258.jpg](https://pic.leetcode-cn.com/b75e245f635ad08e1750e771cb9eef413578252782c86e2bb215c7c3628b3fcb-qrcode_for_gh_6e5f8557b1f8_258.jpg)
