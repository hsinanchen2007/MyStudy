执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :38 MB, 在所有 Java 提交中击败了45.39%的用户

### 解题思路
为避免出错，数组的最后一个元素单独判断

### 代码

```java
class Solution {
    public int compress(char[] chars) {
        int len = chars.length;
        if (len == 1) {
            return 1;
        }
        int answer = 0;
        int pointer = 0;
        int repeatNum = 1;
        String strRepeatNum;
        char lastLetter = ' ';
        for (int i = 0; i < len - 1; i++) {
            if (chars[i+1] == chars[i]) {
                lastLetter = chars[i];
                repeatNum++;
            } else {
                lastLetter = chars[i];
                strRepeatNum = String.valueOf(repeatNum);
                chars[pointer] = chars[i];
                answer++;
                pointer++;
                if (repeatNum != 1){
                    for (int j = 0; j < strRepeatNum.length(); j++) {
                        chars[pointer] = strRepeatNum.charAt(j);
                        pointer++;
                        answer++;
                    }
                }
                repeatNum = 1;
            }
        }
        if (chars[len-1] == lastLetter){
            strRepeatNum = String.valueOf(repeatNum);
            chars[pointer] = lastLetter;
            answer++;
            pointer++;
            if (repeatNum != 1){
                for (int j = 0; j < strRepeatNum.length(); j++) {
                    chars[pointer] = strRepeatNum.charAt(j);
                    pointer++;
                    answer++;
                }
            }
        } else {
            chars[pointer] = chars[len-1];
            answer++;
        }
        return answer;
    }
}
```