### 解题思路

灵感来自于[表驱动法-有效数字](https://leetcode-cn.com/problems/valid-number/solution/biao-qu-dong-fa-by-user8973/)


状态转换图（箭头上的标识表示输入的整数在二进制表示下的前缀）
![image.png](https://pic.leetcode-cn.com/2e47f8dc895fe07a1c49a5e887ee159895ae1d521138ea911a679880b53b65fc-image.png)

状态转移表
|      | 01   | 10   | 110  | 1110 | 11110 |
| ---- | ---- | ---- | ---- | ---- | ----- |
| 0    | 0    | -1   | 3    | 2    | 1     |
| 1    | -1   | 2    | -1   | -1   | -1    |
| 2    | -1   | 3    | -1   | -1   | -1    |
| 3    | -1   | 0    | -1   | -1   | -1    |

合法状态只有state = 0

### 代码

```java
class Solution {
    int make(int d){
        int cnt = -1;
        if(d >> 7 == 0b0) cnt = 0;
        else if(d >> 6 == 0b10) cnt = 1;
        else if(d >> 5 == 0b110) cnt = 2;
        else if(d >> 4 == 0b1110) cnt = 3;
        else if(d >> 3 == 0b11110) cnt = 4;
        return cnt;
    }
    boolean validUtf8(int[] data) {
        int state = 0;
        int finals = 0b1;
        int[][] transfer = new int[][]{
            {0, -1, 3, 2, 1},
            {-1, 2, -1, -1, -1},
            {-1, 3, -1, -1, -1},
            {-1, 0, -1, -1, -1}
        };
        for (int d: data) {
            int id = make(d);
            if(id < 0) return false;
            state = transfer[state][id];
            if(state < 0) return false;
        }
        return state == 0;
    }
};
```