### 解题思路
参考了官网的思路和甜姨的解答

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        //初始状态
        StateEnum state = StateEnum.Start;
        int ans = 0;
        int sign = 1;

        char[] chars = str.toCharArray();
        for(char c : chars){
            state = state.next(c);
            if(state.equals(StateEnum.Signed)){
                if( c == '-'){
                    sign = -1;
                }
                continue;
            }
            if(state.equals(StateEnum.InNumber)){
                int digit = c - '0';
                if (ans > (Integer.MAX_VALUE - digit) / 10) {
                    return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
                }
                ans = ans * 10 + digit;
                continue;
            }
            if(state.equals(StateEnum.End)){
                break;
            }
        }
        return ans * sign;
    }

    public enum StateEnum{

        Start{
            @Override
            public StateEnum next(char c){
                if(Character.isSpaceChar(c)){
                    return Start;
                }
                if(c == '+' || c == '-'){
                    return Signed;
                }
                if(Character.isDigit(c)){
                    return InNumber;
                }
                return End;
            }
        },
        Signed{
            @Override
            public StateEnum next(char c){
                if(Character.isDigit(c)){
                    return InNumber;
                }
                return End;
            }
        },
        InNumber{
            @Override
            public StateEnum next(char c){
                if(Character.isDigit(c)){
                    return InNumber;
                }
                return End;
            }
        },
        End{
            @Override
            public StateEnum next(char c) {
                return End;
            }
        };
        public abstract StateEnum next(char c);
    }
}
```