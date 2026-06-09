第一感觉这道题不难，但是做了发现这道题的难点在于是否能考虑全面。
解题思路如下（仅供参考）：
首先，设定一个擂主，遍历字符串，进行攻擂：
1. 当前字符大于擂主起始字符，则攻擂成功，更换擂主；
2. 当前字符等于擂主起始字符：
   若：当前字符==他左边字符，
       若正在攻擂，判断当前字符与擂主的第(擂主起始Index + 当前字符Index - 攻擂起始Index)个字符进行比较：若当前字符大，攻擂成功，更换擂主；若当前字符小，攻擂失败。若相等，则继续攻擂。
   若：当前字符 != 他左边字符，开始攻擂
3. 当前字符小于擂主起始字符：
    若正在攻擂：判断当前字符与擂主的第(擂主起始Index + 当前字符Index - 攻擂起始Index)个字符进行比较：若当前字符大，攻擂成功，更换擂主；若当前字符小，攻擂失败。若相等，则继续攻擂。

代码如下：

public String lastSubstring(String s) {
        // 最大子串开始字符(擂主)
        char startChar = s.charAt(0);
        // 开始index
        int startIndex = 0;
        int len = s.length();
        // 攻擂子串开始index, 若为0,则没有攻擂子串
        int compareIndex = 0;

        // 开始遍历
        for (int i = 1; i < len; i++) {
            char nowChar = s.charAt(i);
            // 若当前字符=开始字符,判断当前字符是否与前面字符相等
            if (nowChar == startChar) {
                // 若与前面字符不等,则开始攻擂
                if (nowChar != s.charAt(i - 1)) {
                    compareIndex = i;
                } else {
                    // 若与前面字符相等,则校验当前值与擂主进行比较
                    if (compareIndex > 0) {
                        char compareChar = s.charAt(i - compareIndex + startIndex);
                        // 若大于擂主,则攻擂成功,更换擂主
                        if (nowChar > compareChar) {
                            startIndex = compareIndex;
                            compareIndex = 0;
                        } else if (nowChar < compareChar) {
                            // 若小于擂主, 则攻擂失败
                            compareIndex = 0;
                        }
                        // 若相等,则继续攻擂
                    }
                }
            } else if (nowChar > startChar) {
                // 大于startChar,攻擂成功,更换擂主
                startIndex = i;
                startChar = nowChar;
                compareIndex = 0;
            } else {
                // 若没有在攻擂,继续，若在攻擂,进行比较
                if (compareIndex > 0) {
                    char compareChar = s.charAt(i - compareIndex + startIndex);
                    // 若大于擂主,则攻擂成功,更换擂主
                    if (nowChar > compareChar) {
                        startIndex = compareIndex;
                        compareIndex = 0;
                    }  else if (nowChar < compareChar) {
                        // 若小于擂主, 则攻擂失败
                        compareIndex = 0;
                    }
                    // 若相等,则继续攻擂
                }
            }
        }
        return s.substring(startIndex);
    }