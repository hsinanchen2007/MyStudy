### 解题思路
```text
先不考虑特殊情况，如x或y中某一个为空杯，目标值为0等
1. 设x为较小的杯子，y为较大的杯子
2. 初始化时，大杯为整杯水，小杯为空杯
3. 寻找倒换的规律,抽象成函数
水杯x             水杯y
                  y - x
                  y - 2x if y - 2x >0
                  ...
                  y - nx if y - nx > 0
x - (y - nx)      y if y - (n + 1)x < 0, 即将水杯中x倒满，通过水杯x向水杯y注满水，则水杯x剩余水量为x - (y - nx)即(n + 1)x - y
0                 y - [x - (y - nx)] 即2y - (n + 1)x
                  ...
抽象numMax为大杯的数量，numMin为小杯的数量，循环遍历
a. 直到最终结果（水杯y中的值或在倒换的一刻水杯x中的值）为z时停止遍历
b. 否则直到numY*y - numX*x == 0，如果还没找到，则不能满足要求
4. 结束
```
### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        // 边界条件判断，z为0返回true
        // 如果x和y有一个和目标值相等，或其和与目标值相等，则返回true
        if (z == 0 || x == z || y == z || (x + y) == z) {
            return true;
        }

        // 如果上述条件不满足，则x等于0或y等于0，也直接返回false
        if (x == 0 || y == 0) {
            return false;
        }

        // 设置临时变量max， min，保存x和y中的较大值和较小值
        int max, min;
        // 初始化大杯的数量为1
        int numMax = 1;
        // 初始化小杯的数量为1
        int numMin = 1;
        if (y > x) {
            max = y;
            min = x;
        } else {
            max = x;
            min = y;
        }
        //  初始化两杯倒换的初始值为1
        int res = max - min;
        // 如果结果不为0，则一直遍历
        // 最大遍历次数为max * min，因为当numMax == min，numMin == max时，res为0
        while (res != 0) {
            res = numMax * max - numMin * min;
            if (res == z || (res + min) == z) {
                return true;
            }
            if (res < min) {
                if ((numMin + 1) * min - numMax * max == z) {
                    return true;
                }
                numMax++;
                numMin++;
                continue;
            }
            numMin++;
        }
        return false;
    }
}
```

### 测试用例
```Java
public class SolutionTest {
    Solution solution = new Solution();

    @Test
    public void canMeasureWater() {
        int input1_x = 3;
        int input1_y = 5;
        int input1_z = 4;
        boolean res = solution.canMeasureWater(input1_x, input1_y, input1_z);
        assertTrue(res);

        int input2_x = 2;
        int input2_y = 6;
        int input2_z = 5;
        boolean res2 = solution.canMeasureWater(input2_x, input2_y, input2_z);
        assertFalse(res2);

        int input3_x = 34;
        int input3_y = 5;
        int input3_z = 6;
        boolean res3 = solution.canMeasureWater(input3_x, input3_y, input3_z);
        assertTrue(res3);

        int input4_x = 0;
        int input4_y = 2;
        int input4_z = 1;
        boolean res4 = solution.canMeasureWater(input4_x, input4_y, input4_z);
        assertFalse(res4);

        int input5_x = 1;
        int input5_y = 1;
        int input5_z = 0;
        boolean res5 = solution.canMeasureWater(input5_x, input5_y, input5_z);
        assertTrue(res5);
    }
}
```