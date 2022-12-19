### 解题思路
1 优先使用剩余数最多的字符；
2 节省较少的字符。

### 代码

```java
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        // 上次插入的字符索引
        int lastAdded = -1;
        // 各字符剩余使用次数
        int[] count = {a, b, c};
        // 组成串的字符数组
        char[] chars = {'a', 'b', 'c'};
        StringBuilder sb = new StringBuilder();
        while (true) {
            // 比较剩余最多的字符索引
            int i = count[0] >= count[1] ? 0 : 1;
            i = count[i] >= count[2] ? i : 2;
            int tempI = i;
            // 上次使用的字符不能用于本次，选择次多的字符索引
            if(lastAdded == i) {
                i = count[(i + 4) % 3] > count[(i + 5) % 3] ? (i + 4) % 3 : (i + 5) % 3;
                // 不存在可用字符，终止循环
                if(count[i] == 0) {
                    break;
                }
            }
            // 当前字符剩余不是最多，节省使用
            int loop = count[tempI] > count[i] ? 1 : 2;
            // 拼接字符
            for(int j = 0; j < loop && count[i] > 0; j++) {
                sb.append(chars[i]);
                count[i]--;
            }
            //标记本次拼接索引
            lastAdded = i;
        }
        return sb.toString();
    }
}
```