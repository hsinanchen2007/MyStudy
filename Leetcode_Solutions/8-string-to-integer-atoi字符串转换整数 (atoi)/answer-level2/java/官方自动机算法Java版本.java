### 解题思路
什么鬼，官方题解还没我写的很low的那一版本效率高？？？？？？？  以下代码为自动机的java版本。

### 代码

```java
class Solution {

    Map<String, String[]> stateMap;

    String state = "start";


    public Solution() {
        stateMap = new HashMap();
        stateMap.put("start", new String[]{"start","sigined","number","end"});
        stateMap.put("sigined", new String[]{"end","end","number","end"});
        stateMap.put("number", new String[]{"end","end","number","end"});
        stateMap.put("end", new String[]{"end","end","end","end"});
    }

    public int myAtoi(String str) {
        long ans = 0;
        boolean isF = false;
        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);
            state = stateMap.get(state)[getColValue(c)];
            if("sigined".equals(state)) {
                if('-' == c) isF = true;
            } else if("number".equals(state)) {
                ans = ans * 10 + (c - '0');
                ans = isF ? getMin(ans, -(long)Integer.MIN_VALUE) : getMin(ans, Integer.MAX_VALUE);
            } else if("end".equals(state)) {
                break;
            }
        }
        return isF ? -(int) ans : (int)ans;
    }

    public long getMin(long a1, long a2) {
        return a1 > a2 ? a2 : a1;
    }

    public int getColValue(char c) {
        if(' ' == c) return 0;
        if('+' == c || '-' == c) return 1;
        if('0' <= c && '9'>= c) return 2;
        return 3;
    }


}
```