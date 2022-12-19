### 解题思路
不妨写几个二进制数，找找规律
0---0
1---1
2---10
3---11
4---100
5---101
6---110
7---111
8---1000
不难发现，对于是2的n次方，结果是1，而那些不是2的n次方，去掉最高位的1，剩下来的结果我们之前已经计算过，比如7=4+3，6=4+2，9=8+1；

至此，我们其实只需要标记最高位就可以了

### 代码

```java
class Solution {
   public static int[] countBits(int num) {
        int[] data = new int[num + 1];
        if (num == 0) {
            return data;
        }
        //预置数据
        data[1] = 1;
        //标记最高位
        int last = 1;
        for (int i = 1; i <= num; i++) {
            //如果相等，置1，最高位本身也乘2
            if (i == last * 2) {
                data[i] = 1;
                last = last * 2;
            } else {
                //不等，去掉最高位且加1
                data[i] = data[i - last] + 1;
            }
        }
        return data;
    }
}
```