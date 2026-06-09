### 解题思路
这题的难点就在于能不能想明白，需要得到什么，是考你需要翻转第几列吗，不是，只需要知道最后最多的行的数量。

那么怎么判断行的数量？

首先要知道，怎么判断两个行的能否经过一定的翻转达到全行相同。
- 000 和 111 这两个是一样的；
- 010 和 101 这两个也是一样的，因为它们可以通过翻转第二列完成相同。
- 110 和 001 也是一样，因为不管是翻转前两列还是翻转最后一列，都会让两行都进入相同的状态。

不知道能否从上面的这些想到二进制？然后能不能根据观察想到 “异或” 操作？
因为
010 ^ 101 = 111;
110 ^ 001 = 111;

更多的例子，比如：
1011 ^ 0100 = 1111;
0001 ^ 1110 = 1111;

所以，我们看出，如果两个行是可以通过翻转相同的列达到全行相同，那么就要满足，**两行的相同的位置上的值异或之后等于全1** 。
那我们可以根据 异或 操作的特征： 
a ^ b = c
那么 
a ^ c = b

我们已知 c 是全1，那有没有什么好的方法，用一个统一的规则，让所有的行完成归一？
我们已知，相同特征的行，每个位置都是不同的，那么我们能不能规定，第一位是 “0” 的就是 a，第一位是 “1”的就是b？
具体的规则就是，
1 如果第一位是 `0` 的话，那么就把全行都不用异或操作，直接转为字符串类型，作为key保存，且 value + 1。
2 如果第一位是 `1` 的话，那么就把全行的每个位置上的值都和 `1` 进行异或操作，然后转为字符串类型，作为key保存在下来，且 value+1。

最后，遍历map，取最大的那个value。

### 代码

```java
class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        Map<String, Integer> map = new HashMap<>();
        boolean firstZero = false;
        int res = 0;
        for (int i = 0, len = matrix.length; i < len; i++) {
            if (matrix[i][0] == 0) {
                firstZero = true;
            } else {
                firstZero = false;
            }
            StringBuilder temp = new StringBuilder();
            for (int j = 0, colLen = matrix[i].length; j < colLen; j++) {
                if (firstZero) {
                    temp.append(matrix[i][j]);
                } else {
                    temp.append((matrix[i][j] ^ 1));
                }
            }
            String tempStr = temp.toString();
            res  = Math.max(map.getOrDefault(tempStr, 0) + 1, res);
            map.put(tempStr, map.getOrDefault(tempStr, 0) + 1);
        }   
        return res;
    }
}
```