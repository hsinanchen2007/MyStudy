### 解题思路
用3个bit位表示每行座位预定状态：如果2~5号被预定，则bit 1置位；如果4~7号被预定，则bit 2置位；如果6~9号被预定，则bit 3置位。HashMap只保存预定了2~9号座位的行号以及对应作为预定状态，降低空间的使用量，以满足空间限制。

计算能满足的家庭数时，首先将没被预定2~9号座位的行数乘2，然后遍历预定了2~9号座位的行号，如果预定状态不是7（3个bit位都置位），则能满足的家庭数加一。（一开始用的是遍历所有行的方式，会超出时间限制Orz）

### 代码

```java
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        // 1: left (2345); 2: middle (4567); 4: right (6789)
        HashMap<Integer, Integer> occupy = new HashMap<>();
        for (int i = 0; i < reservedSeats.length; i++) {
            int row = reservedSeats[i][0];
            int occupyMask = occupy.getOrDefault(row, 0);
            int col = reservedSeats[i][1];
            switch (col) {
                case 2:
                case 3:
                    occupyMask |= 0b001; break;
                case 4:
                case 5:
                    occupyMask |= 0b011; break;
                case 6:
                case 7:
                    occupyMask |= 0b110; break;
                case 8:
                case 9:
                    occupyMask |= 0b100; break;
            }
            if (occupyMask > 0)
                occupy.put(row, occupyMask);
        }
        // 没有预定2~9号座位的每行可容纳2个家庭
        int num = (n - occupy.size()) * 2;
        for (int row : occupy.keySet()) {
            if (occupy.get(row) < 7)
                num += 1;
        }
        return num;
    }
}
```