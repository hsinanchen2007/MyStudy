### 解题思路

**一条直线上的点代表着：任何两个点直接的斜率是相同的**

- 任意两个点都在一条直线上；
- n个点能够组成直线，那么n-1个点也是直线。
- 如果n-1个点在直线上，那么n点是否在这个直线上，取决于n点和n-1个点中的任意一个点形成的斜率是否和n-1个点的斜率相同。
- 斜率可以定义为 = (y2-y1)/(x2-x1), 这里定义x2 >= x1
- 考虑到除不尽或者除数为零的情况，避免使用除法
    - 设x2>=x1, x3>=x2:    (x3-x2) * (y2-y1) == (y3-y2) * (x2-x1)


### 代码

```java
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        //除数
        int divisor = coordinates[1][0] - coordinates[0][0];
        //被除数
        int dividend = 0;
        if(divisor >= 0) {
            dividend = (coordinates[1][1] - coordinates[0][1]);
        } else {
            divisor *= -1;
            dividend = (coordinates[0][1] - coordinates[1][1]);
        }
        for(int i=2; i < coordinates.length; i++) {
            int dr = coordinates[i][0] - coordinates[i-1][0];
            int dd = 0;
            if(dr >= 0) {
                dd = (coordinates[i][1] - coordinates[i-1][1]);
            } else {
                dr *= -1;
                dd = (coordinates[i-1][1] - coordinates[i][1]);
            }
            if(dd * divisor != dr * dividend) {
                return false;
            }
        }
        return true;
    }


    /*
    int condition = 0;//1: x相同，2: y相同，3:差值相同, 4等差
        if(coordinates[0][0] == coordinates[1][0]) {
            condition = condition | 1;
        }
        if(coordinates[0][1] == coordinates[1][1]) {
            condition = condition | 2;
        }
        if(condition == 0) {
            condition = 4;
        }
        for(int i=2; i<coordinates.length; i++) {
            int c = 0;
            if(coordinates[i][0] == coordinates[i-1][0]) {
                c = c | 1;
            }
            if(coordinates[i][1] == coordinates[i-1][1]) {
                c = c | 2;
            }
            condition = condition & c;
            if(condition == 0) {
                return false;
            }
        }

        return true;
    */
}
```