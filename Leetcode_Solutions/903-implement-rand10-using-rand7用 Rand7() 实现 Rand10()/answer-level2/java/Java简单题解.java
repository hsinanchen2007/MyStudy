### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10() {
            int flag;
            while (true) {
                flag = rand7();
                if (flag != 4) break;
            }
            int value;
            while (true) {
                value = rand7();
                if (value <= 5) break;
            }
            if (flag > 4) value += 5;
            return value;
        }
}
```
1. 第一次rand7的调用用来随机选择, 下一次调用rand7的结果用来表示前5个数, 还是后5个数
2. 第二次rand7的调用用来作为结果值, 若flag大于4则为后5个数, 结果值加加5, 就可以表示 `6, 7, 8, 9, 10` , 若flag<4则表示 `1, 2, 3, 4, 5`. 而且flag>4或<4的概率是相同的.
