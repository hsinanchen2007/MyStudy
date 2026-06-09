### 解题思路
思路很简单，子问题为前i个字符串的解码总数，记录前i个字符串的第i个字符为单个字符的方法总量
记录前i个字符第i个字符与第i-1个字符组成一个字母的方法总量，
然后根据各种条件，开始递推到n，难点在条件处理上，因为多出一个0的情况，
调了6次才成功，主要问题就出在对0的情况处理上；

### 代码

```java
class Solution {
    public int numDecodings(String s) {

        if (s.charAt(0) == '0') {
            return 0;
        }
        if (s.length() < 2) {
            return s.length();
        }
        
        char lastNum = s.charAt(0);
        // 上一种状态下只有一个字母的情况
        int lastSumOne = 1;
        // 上一种状态下有两个字母的情况
        int lastSumTwo = 0;
        for (int i=1;i<s.length();i++) {
            char c = s.charAt(i);
            // 先处理当前字符为0的情况
            if (c == '0') {
                if (lastNum == '0') {
                    return 0;
                } else if (lastNum < '3') {
                    lastSumTwo = lastSumOne;
                    lastSumOne = 0;
                } else {
                    return 0;
                }
                lastNum = c;
                continue;
            }
            // 接着处理前一个字符为0,1,2和大于2的情况，注意大情况下的子情况，都注意到了就没问题了
            if (lastNum == '0') {
                lastSumOne += lastSumTwo;
                lastSumTwo = 0;
            } else if(lastNum == '1') {
                int temp = lastSumOne;
                    lastSumOne += lastSumTwo;
                    lastSumTwo = temp;
            } else if (lastNum == '2') {
                if (c < '7') {
                    // 当前字母可以融合
                    int temp = lastSumOne;
                    lastSumOne += lastSumTwo;
                    lastSumTwo = temp;

                } else {
                    // 当前字母不可以融合，只能做单个
                    lastSumOne += lastSumTwo;
                    lastSumTwo = 0;
                }
                
            } else {
                // 当前字母不可以融合，只能做单个
                lastSumOne += lastSumTwo;
                lastSumTwo = 0;
            }
            lastNum = c;
        }
        return lastSumOne + lastSumTwo;
    }
}
```