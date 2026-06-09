### 解题思路
欢迎关注，这是我的公众号
![二维码.jpg](https://pic.leetcode-cn.com/c4be10e56a6ea79e4ece2bdef6a57226776aff8fd3dfac90c86a558e6ba0165c-%E4%BA%8C%E7%BB%B4%E7%A0%81.jpg)
这是我的CSDN[https://blog.csdn.net/every__day]()

今天的题目描述的不清楚，看了例子才知道是啥意思，可能是因为我不太懂国际象棋吧！
### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        //找到车后四个方向上遍历
        int count = 0;
        int[] m = {0, 0, 1, -1};
        int[] n = {-1, 1, 0, 0};
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){                   
                    for(int k = 0; k < 4; k++){
                        int x = i;
                        int y = j;
                        while(x > -1 && x < 8 && y > -1 && y < 8){
                            
                            if(board[x][y] == 'B'){
                                break;
                            }
                            if(board[x][y] == 'p'){
                                count++;
                                break;
                            } 
                            x += m[k];
                            y += n[k];                          
                        }
                    }
                }
            }
        }
        return count;

    }
}
```