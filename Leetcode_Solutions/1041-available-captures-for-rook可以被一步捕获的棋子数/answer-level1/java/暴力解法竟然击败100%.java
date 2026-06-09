### 解题思路
![批注 2020-03-26 125740.png](https://pic.leetcode-cn.com/d14e0178a8d7ae4a8700aed28a9edb2ca195bce413c7f74fbd4b56aa623d9388-%E6%89%B9%E6%B3%A8%202020-03-26%20125740.png)
暴力解法，代码有点长

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int num = 0, size = board.length, row = 0, col = 0;
    out:
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (board[i][j] == 'R') {
          row = i;
          col = j;
          break out;
        }
      }
    }
    int times = 0,temp1 ,temp2 ;
    char temp;
    while(times < 4){
        temp1 = row;
        temp2 = col;
        switch (times){
          case 0:
            while(times == 0){
              temp1++;
              temp = temp1 < size ? board[temp1][temp2] : 'a';
              num += temp == 'p'  ? 1 : 0;
              times += temp!= '.'? 1 : 0;
            }
            break;
          case 1:
            while(times == 1){
            temp1--;
            temp = temp1 >= 0 ? board[temp1][temp2] : 'a';
            num += temp == 'p'  ? 1 : 0;
            times += temp!= '.'? 1 : 0;
          }
            break;
          case 2:
            while(times == 2){
              temp2++;
              temp = temp2 < size ? board[temp1][temp2] : 'a';
              num += temp == 'p'  ? 1 : 0;
              times += temp!= '.'? 1 : 0;
            }
            break;
          case 3:
            while(times == 3){
              temp2--;
              temp = temp2 >= 0 ? board[temp1][temp2] : 'a';
              num += temp == 'p'  ? 1 : 0;
              times += temp != '.' ? 1 : 0;
            }
            break;

        }
    }
    return num;
    }
}
```