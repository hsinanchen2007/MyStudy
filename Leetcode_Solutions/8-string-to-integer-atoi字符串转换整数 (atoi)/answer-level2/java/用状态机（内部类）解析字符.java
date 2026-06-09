### 解题思路
之前用类似状态机做了一次。做完一看官方的 状态自动机python版，重新做了一次。
思路与官方的一样，只不过把状态机封装在了一个独立的内部类了。
理论上，状态机类封装条件转移，parser的switch/case用各个状态的处理函数handler来完成各类工作。

### 代码

```java
class Solution {
    static class NumberSTATE{
        public final static char START =0;
        public final static char SIGN = 1;
        public final static char NUMBER = 2;
        public final static char END = 3;
        ///             ' '   '+-'  '[0-9]'  other
        private final static char[][] STATETable 
         ={ /*START*/  {START, SIGN, NUMBER, END},
            /*SIGN */  {END, END, NUMBER, END},
            /*Number*/ {END, END, NUMBER, END},
            /*End*/    {END, END, END, END} };
        public static char getNextState(char curState, char curChar){
            int columnIndex = 0;

            switch(curChar){
            case ' ':
                columnIndex =0;
                break;
            case '+':
            case '-':
                columnIndex = 1;
                break;
            default:
                if(curChar>='0' && curChar<= '9'){
                    columnIndex = 2;
                }else{
                    columnIndex = 3;
                }
            break; 
            }

            return STATETable[curState][columnIndex];
        }
    }

    public int myAtoi(String str) {
        if(str ==null || "".equals(str)){
            return 0;
        }
        int strLen = str.length();

        int sign = 1;
        int retValue = 0;
        char curState = NumberSTATE.START;
        for(int index =0; index < strLen; index++){
            char c = str.charAt(index);
            curState = NumberSTATE.getNextState(curState, c);

            switch(curState){
            case NumberSTATE.START:
                break;
            case NumberSTATE.SIGN:
                sign = (c=='-') ? -1 : 1;
                break;
            case NumberSTATE.NUMBER:
                int d = (c-'0');
                if(sign ==-1 && (retValue<Integer.MIN_VALUE/10 ||(retValue==Integer.MIN_VALUE/10 && d>=Math.abs(Integer.MIN_VALUE%10)))){
                    return Integer.MIN_VALUE;
                }else if(sign ==1 && (retValue>Integer.MAX_VALUE/10 || (retValue==Integer.MAX_VALUE/10 && d>=Math.abs(Integer.MAX_VALUE%10)))){
                    return Integer.MAX_VALUE;
                }
                retValue = retValue*10 + sign*d;
                break; 
            case NumberSTATE.END:
                break;
            }
        }
        return retValue;
    }

}
```