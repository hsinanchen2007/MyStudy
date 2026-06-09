可以分析出状态转移:
||0|10|11|111|1111|
|:-:|:-:|:-:|:-:|:-:|:-:|
|Start1|Start1|Invalid|Start2|Start3|Start4|
|Start2|Invalid|Start1|Invalid|Invalid|Invalid|
|Start3|Invalid|Rest1|Invalid|Invalid|Invalid|
|Start4|Invalid|Rest2|Invalid|Invalid|Invalid|
|Rest1|Invalid|Start1|Invalid|Invalid|Invalid|
|Rest2|Invalid|Rest1|Invalid|Invalid|Invalid|

解释: 如果我们当前处于 Start1 状态，那么当我们遇到的下一个二进制数字以 0 作为开头，也就是说遇到了一个字节的 utf 编码，那么我们仍然处于 Start1状态。如果遇到了一个以 10开头的，那么是不合法的。如果遇到以 11 开头的，那么进入 Start2 状态。以此类推。
如果我们当前处于 Start4 状态，当我们遇到了一个 10 时，那么后面还需要 2 个数字以 10 开头，所以处于 Rest2状态。 
```java
class Solution {
    private final static String START1 = "start1";
    private final static String START2 = "start2";
    private final static String START3 = "start3";
    private final static String START4 = "start4";
    private final static String REST1 = "rest1";
    private final static String REST2 = "rest2";
    private final static String INVALID = "invalid";

    private Map<String, String[]> transfer;
    private String state = START1;
    public Solution() {
        transfer = new HashMap<>();
        transfer.put(START1, new String[]{START1, INVALID, START2, START3, START4});
        transfer.put(START2, new String[]{INVALID, START1, INVALID, INVALID, INVALID});
        transfer.put(START3, new String[]{INVALID, REST1, INVALID, INVALID, INVALID});
        transfer.put(START4, new String[]{INVALID, REST2, INVALID, INVALID, INVALID});
        transfer.put(REST1, new String[]{INVALID, START1, INVALID, INVALID, INVALID});
        transfer.put(REST2, new String[]{INVALID, REST1, INVALID, INVALID, INVALID});
    }

    private int getPrefix(int dat) {
        int prefix = dat >> 3;
        if (prefix < 16) return 0;
        if (prefix >= 16 && prefix < 24) return 1;
        if (prefix >= 24 && prefix < 28) return 2;
        if (prefix >= 28 && prefix < 30) return 3;
        if (prefix == 30) return 4;
        // prefix is invalid
        return -1;
    }
    public boolean validUtf8(int[] data) {
        for (Integer dat : data) {
            int prefix = getPrefix(dat);
            if (prefix == -1) return false;
            state = transfer.get(state)[prefix];
            if (state.equals(INVALID)) return false;
        }
        if (!state.equals(START1)) return false;
        return true;
    }
}
```
