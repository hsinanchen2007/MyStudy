### 解题思路
有限状态机
写的不好 请大家给点建议 

### 代码

```java
class Solution {
    enum FSMStatus {

        START("start"),
        SIGNED("signed"),
        NUMBER("number"),
        END("end");

        private String name;

        FSMStatus(String str) {
            name = str;
        }

        @Override
        public String toString() {
            return "FSMStatus is " + name;
        }
    }

    /**
     * Finite-state machine
     */
    static class Fsm {

        private final static HashMap<FSMStatus, FSMStatus[]> table;

        private final static int START_INDEX = 0;
        private final static int SIGNED_INDEX = 1;
        private final static int NUMBER_INDEX = 2;
        private final static int END_INDEX = 3;

        private final static char BLANK = ' ';
        private final static char PLUS  = '+';
        private final static char MINUS = '-';

        private FSMStatus curStatus;
        private long num;
        private boolean isNegative;


        static {
            table = new HashMap<>();
            table.put(FSMStatus.START, new FSMStatus[]{FSMStatus.START, FSMStatus.SIGNED, FSMStatus.NUMBER, FSMStatus.END});
            table.put(FSMStatus.SIGNED, new FSMStatus[]{FSMStatus.END, FSMStatus.END, FSMStatus.NUMBER, FSMStatus.END});
            table.put(FSMStatus.NUMBER, new FSMStatus[]{FSMStatus.END, FSMStatus.END, FSMStatus.NUMBER, FSMStatus.END});
            table.put(FSMStatus.END, new FSMStatus[]{FSMStatus.END, FSMStatus.END, FSMStatus.END, FSMStatus.END});
        }

        public Fsm() {
            curStatus = FSMStatus.START;
            num = 0;
            isNegative = false;
        }

        public boolean isEnd() {
            return curStatus.equals(FSMStatus.END);
        }

        public Fsm update(char c) {
            int index = getCharStatusIndex(c);
            curStatus = table.get(curStatus)[index];

            if (curStatus.equals(FSMStatus.SIGNED))
                isNegative = c == MINUS;
            if (curStatus.equals(FSMStatus.NUMBER))
                num = num * 10 + c - '0';

            return this;
        }

        public int getNum() {
            long ret = isNegative ? -1 * num : num;
            if (ret > Integer.MAX_VALUE)
                return Integer.MAX_VALUE;
            if (ret < Integer.MIN_VALUE)
                return Integer.MIN_VALUE;
            return (int)ret;
        }

        protected int getCharStatusIndex(char c) {
            if (BLANK == c)
                return START_INDEX;
            if (MINUS == c || PLUS == c) {
                return SIGNED_INDEX;
            }
            if (Character.isDigit(c)) {
                if (num <= Integer.MAX_VALUE)
                    return NUMBER_INDEX;
            }
            return END_INDEX;
        }
    }


    /**
     * 使用有限状态机
     *
     * @param str 输入字符串
     * @return int
     */
    public int myAtoi(String str) {
        if (Objects.isNull(str) || 0 == str.length())
            return 0;

        Fsm fsm = new Fsm();
        for (char c: str.toCharArray()) {
            if (fsm.update(c).isEnd())
                break;
        }
        return fsm.getNum();
    }

}
```