a->0b00001，e->0b00010，i->0b00100，o->0b01000，u->0b10000，五个位共2^5个组合，使用int类型status存储状态，当a为偶数个时二进制第1为为0，当e为偶数个时二进制第2位为0，其他元音字符同理，所以当status为0时所有元音字符都是偶数次。利用按位异或运算可以切换0和1。
动态规划数组statusPos以状态status为下标，最早一次出现该状态的位置作为值。当前位置和最早一次出现该状态的位置之间字符串便是一个合法字符串。

```java
class Solution {
    public int findTheLongestSubstring(String s) {
        int m = 0;
        
        int status = 0;
        
        int[] statusPos = new int[1 << 5];
        Arrays.fill(statusPos, -1);
        statusPos[status] = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            status ^= getCode(c);
            if (statusPos[status] >= 0) {
                m = Math.max(m, i + 1 - statusPos[status]);
            } else {
                statusPos[status] = i + 1;
            }
        }
        
        return m;
    }
    
    private int getCode(char c) {
        switch (c) {
            case 'a':
                return 1;
            case 'e':
                return 2;
            case 'i':
                return 4;
            case 'o':
                return 8;
            case 'u':
                return 16;
        }
        return 0;
    }
}
```

