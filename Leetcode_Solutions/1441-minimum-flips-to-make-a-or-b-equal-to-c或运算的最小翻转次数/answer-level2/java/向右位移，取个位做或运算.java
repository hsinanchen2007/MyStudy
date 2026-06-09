### 解题思路
1. 取三个数字的个位数，看 a | b == c 是否成立，成立则不用转换
2. 否则，c == 1 则说明 a = b = 0, 则a和b只有一个转成1就可以了，需要转换1次
3. c == 0, 如果 a = b = 1,则要都变为0，需要转换2次，如果 a != b 则说明a 和 b 有一个是1 ，只需转换一次就够了
![image.png](https://pic.leetcode-cn.com/eb96f761165324617ed3c99c099f4605e1ebd4def6548f882c59e5cf5f28c685-image.png)

### 代码

```java
class Solution {
    public int minFlips(int a, int b, int c) {
        int count = 0;
        while (c > 0 || a > 0 || b > 0) {
            int tempC = c & 1;
            int tempA = a & 1;
            int tempB = b & 1;
            if (tempC != (tempA | tempB)) {
                if (tempC == 0) {
                    count += (tempA == tempB ? 2 : 1);
                } else {
                    count += 1;
                }
            }
            c = c >> 1;
            a = a >> 1;
            b = b >> 1;
        }
        return count;
    }
}
```