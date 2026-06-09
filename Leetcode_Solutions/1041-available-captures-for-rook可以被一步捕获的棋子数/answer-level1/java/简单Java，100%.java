// 🙋打卡～

// ``` Java
class Solution {
    public int numRookCaptures(char[][] board) {
        // 定义上下左右四个方向
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
       
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                // 找到白车所在的位置
                if (board[i][j] == 'R') {
                    // 分别判断白车的上、下、左、右四个方向
                    int res = 0;
                    for (int k = 0; k < 4; k++) {
                        int x = i, y = j;
                        while (true) {
                            x += dx[k];
                            y += dy[k];
                            if (x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] == 'B') {
                                break;
                            }
                            if (board[x][y] == 'p') {
                                res++;
                                break;
                            }
                        }
                    }
                    return res;
                }
            }
        }
        return 0;
    }
}
// ```



// 看见评论区有人说“不是移动一次吗怎么可以换方向”，其实题目的意思可以理解为移动一次吃到卒的方案有多少种
// （示意图如下，3个卒都可以移动一次车就吃到）
// 所以就是先找到车的位置，然后从这个位置开始遍历上下左右4个方向，如果遇到了卒就res+1并退出循环，如果遇到了象或者出界了就退出循环。

// ![image.png](https://pic.leetcode-cn.com/2637aa62544ffc820f796c1be610e87f6609fc16e4f6727fffb5f2d6315da956-image.png){:height="40%" width="40%"}



// 大佬们随手关注下我的wx公众号【[甜姨的奇妙冒险](https://pic.leetcode-cn.com/304599b006dd41bcf2042715f31a2dc4fbdc4cf9748a11a81d8978ea1e839956-wxgzh.jpeg)】和 知乎专栏【[甜姨的力扣题解](https://zhuanlan.zhihu.com/c_1224355183452614656)】
// ，更多干货快到碗里来～