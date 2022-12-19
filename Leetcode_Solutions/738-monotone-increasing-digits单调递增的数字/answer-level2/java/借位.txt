### 解题思路
借位思想

### 代码

```java
class Solution {
    public int monotoneIncreasingDigits(int num) {

        List<Integer> list = new ArrayList();

        // 变成数组方便处理
        while (num != 0) {
            list.add(num % 10);
            num /= 10;
        }
        // 借位思想，遇到前一位大于后一位，想前一位借1（减1），后一位至最末位填9
        // 借位无需考虑0特殊情况，因为0小于任何数
        for (int i = 1; i < list.size(); ++i) {
            if (list.get(i - 1) < list.get(i)) {
                // 都置9
                for (int j = i - 1; j >= 0; --j) {
                    list.set(j, 9);
                }
                // 减1
                list.set(i, list.get(i) - 1);
            }
        }

        // 接下来是把处理完成的数组恢复成整数
        Collections.reverse(list);
        int pos = 0;
        // 开头的零清掉
        for (int i = 0; i < list.size(); ++i) {
            if (list.get(i) != 0) {
                pos = i;
                break;
            }
        }
        int ans = 0;
        for (; pos < list.size(); ++pos) {
            ans = ans * 10 + list.get(pos);
        }
        return ans;
    }
}
```