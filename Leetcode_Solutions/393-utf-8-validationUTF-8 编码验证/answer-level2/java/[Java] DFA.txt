**思考**
这显然是一题和位操作有关的题目。并且，这其中有非常多的状态需要考虑。UTF-8编码的字符可以是由1到4个字节来表示，并且从第1个字节我们就可以看出该UTF-8字符一共由几个字节组成。所以，当我们接收到第一个字节，后续的0到3个字节必须符合所有题设限制（字节数目限制、每个字节的前导比特限制）。这内部其实是一个很完整的确定有限状态机（DFA）。这里，我们选择直接建立这个自动机。
**算法**
例如，状态0表示clear，即所有之前的字节都已经处理成UTF-8字符了。接下来，有效的输入其实只有4种，所以0这个状态其实可以转移成4个其他状态：
- `0xxxxxxx`，表示单字节UTF-8字符，那么其实可以直接转移回0（clear）。
- `110xxxxx`，表示双字节UTF-8字符，定义一个新状态1。
- `1110xxxxx`，表示三字节UTF-8字符，定义一个新状态2。
- `11110xxx` ，表示四字节UTF-8字符，定义一个新状态3。

剩下的状态转移可以依次类推，下面我直接给出了DFA。
![image_1580299754.png](https://pic.leetcode-cn.com/c10666acd2caef8235c204a12941fd74d87fd4ffb39ed747d35eaaf1f69772f6-image_1580299754.png)

我们看一个最长转移路径：`0` -> `3` -> `5` -> `6` -> `0`，这条路径代表一个4字节的有效UTF-8字符——当我们依次接收到`11110xxx`, `10xxxxxx`, `10xxxxxx`, `10xxxxxx`,状态又跳回了clear态，即0。所有不符合这个路径特征的输入，都可以直接认为是一个无效的UTF-8字符。
**Complexity**
Time: O(n)
Space: O(1)
**Code**
```java
class Solution {
    // input types: determined by most significant 1 ~ 5 bits
    static final int TYPE_0 = 0b00000000;
    static final int TYPE_1 = 0b10000000;
    static final int TYPE_2 = 0b11000000;
    static final int TYPE_3 = 0b11100000;
    static final int TYPE_4 = 0b11110000;
    // masks for most significant 1 to 5 bis
    static final int[] MASKS = new int[]{0b10000000, 0b11000000, 0b11100000, 0b11110000, 0b11111000};
    // input type enumation
    static final int[] TYPES = new int[]{TYPE_0, TYPE_1, TYPE_2, TYPE_3, TYPE_4};
    // map of cur_stat : (input_type : next_stat)
    static final Map<Integer, Map<Integer, Integer>> DFA = new HashMap<>();
    // build the dfa
    static {
        DFA.put(0, Map.of(TYPE_0, 0, TYPE_2, 1, TYPE_3, 2, TYPE_4, 3));
        DFA.put(1, Map.of(TYPE_1, 0));
        DFA.put(2, Map.of(TYPE_1, 4));
        DFA.put(4, Map.of(TYPE_1, 0));
        DFA.put(3, Map.of(TYPE_1, 5));
        DFA.put(5, Map.of(TYPE_1, 6));
        DFA.put(6, Map.of(TYPE_1, 0));
    }
    
    public boolean validUtf8(int[] data) {
        int cur = 0;
        for (int input : data) {
            Integer next = getNext(cur, input);
            if (next == null) {
                return false;
            }
            cur = next;
        }
        return cur == 0;
    }

    private static int getType(int in) {
        for (int i = 0; i < TYPES.length; i++) {
            if ((MASKS[i] & in) == TYPES[i]) {
                return TYPES[i];
            }
        }
        // unreachable. unless input is "11111xxx" which is not a valid utf-8 character.
        return -1;
    }
    
    private static Integer getNext(int cur, int input) {
        int type = getType(input);
        if (type == -1) return null;
        return DFA.get(cur).get(type);
    }
}
```