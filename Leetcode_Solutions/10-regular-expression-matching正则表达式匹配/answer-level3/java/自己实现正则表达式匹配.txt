```
package strings;

import java.util.Stack;

/**
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * <p>
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * <p>
 * <p>
 * <p>
 * <p>
 * <p>
 * <p>
 * 析：
 * [a-z] 直接处理
 * <p>
 * [aab] 匹配 c*a*b*
 * <p>
 * a* 直接匹配a{0}个，如果符合条件，直接进入下一个匹配;
 * 如果不符合条件回溯进入a{1}匹配,依次类推， .*
 * <p>
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/regular-expression-matching
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class SimpleRegex {

    public static class TokenState {
        char c;
        int matchCount;
        int startPos; //开始下标
        int endPos; //结束下标
        int matchPos;

        public TokenState(char c, int matchCount, int startPos, int endPos, int matchPos) {
            this.c = c;
            this.matchCount = matchCount;
            this.startPos = startPos;
            this.endPos = endPos;
            this.matchPos = matchPos;
        }

        public int nextMatchPos(){
            return this.matchPos + 1;
        }

        boolean isAlpha() {
            return 'a' <= c && c <= 'z';
        }

        boolean isDot() {
            return c == '.';
        }

        boolean isStar() {
            return c == '*';
        }

        public boolean canMatch(String p, char ch) {
            if (c == '.' && isAlpha(ch)) return true;
            if (isAlpha(c)) return ch == c;
            if (c == '*' && p.charAt(matchPos - 1) == '.') return true;
            if (c == '*' && isAlpha(p.charAt(matchPos - 1))) return p.charAt(matchPos - 1) == ch;
            return false;
        }


        public static boolean isAlphaOrDot(char ch) {
            return isAlpha(ch) || isDot(ch);
        }

        public static boolean isAlpha(char ch) {
            return 'a' <= ch && ch <= 'z';
        }

        public static boolean isDot(char ch) {
            return ch == '.';
        }

        public static boolean isStar(char ch) {
            return ch == '*';
        }
    }

    Stack<TokenState> tokenStates = new Stack<>();

    public boolean isMatch(String s, String p) {
        tokenStates.clear();
        s = s + "$";
        int i = 0;
        int j = 0;
        boolean matchSucceed = true;
        while (j < p.length()) {
            if(s.length() == i ) break;

            if(p.charAt(j) == '$' && s.charAt(i) == '$') {
                break;
            }

            char regexCurrChar = p.charAt(j);
            char regexNextChar =  j + 1 < p.length() ? p.charAt(j + 1): '$';
            char currChar = s.charAt(i);

            if (!TokenState.isStar(regexCurrChar)) {
                if (!TokenState.isStar(regexNextChar) && matchSucceed) {

                    if (currChar != '$' && (currChar == regexCurrChar || regexCurrChar == '.')) {
                        TokenState tokenState = new TokenState(regexCurrChar, 1, i, i + 1, j);
                        tokenStates.push(tokenState);
                        i = tokenState.endPos;
                        j = tokenState.nextMatchPos();
                    } else {
                        matchSucceed = false;
                    }
                } else if (TokenState.isStar(regexNextChar) && matchSucceed) {
                    TokenState starState = matchStar(s, p, i, j);
                    i = starState.endPos;
                    j = starState.nextMatchPos();
                } else if (!matchSucceed) {
                    if(tokenStates.isEmpty()) return false;
                    if(!tokenStates.peek().isStar()) {
                        tokenStates.pop();
                    }
                    else{
                        TokenState token = tokenStates.peek();
                        if(token.matchCount == 0){
                            tokenStates.pop();
                        }
                        if (token.matchCount > 0) {
                            token.matchCount--;
                            token.endPos--;
                            i = token.endPos;
                            j = token.nextMatchPos();
                            matchSucceed = true;

                        }
                    }
                }
            }
        }
        if(i >= s.length()) return false;
        if ((s.charAt(i) == '$' && j == p.length())) return true;
        return false;
    }

    private TokenState matchStar(String s, String p, int i, int j) {
        int k;
        TokenState starState = new TokenState('*', 0, i, i + 1, j + 1);
        for (k = i; k < s.length() - 1; k++) {
            if (!starState.canMatch(p, s.charAt(k))) {
                break;
            }
        }
        starState.matchCount = k - i;
        starState.startPos = i;
        starState.endPos = k;
        tokenStates.push(starState);
        return starState;
    }

    public static void main(String[] args) {
        System.out.println(new SimpleRegex().isMatch("ab", ".*.."));

    }
}

```

这里使用了贪婪匹配；
每次匹配预读regex 字符串2个字符，当前字符和接下来的字符
判定是否是*模式 例如 a*
如果不是*模式将匹配后的结果， 包括记录匹配到的字符串的起始位置和结束位置推入栈中。

如果是*模式使用贪婪匹配匹配最多的字符推入栈中。

如果遇到不匹配，如果栈顶为空；返回不匹配

如果栈顶是*模式，*模式 匹配字符串-1， 更新*模式结束位置-1，若减为0 则出栈

如果栈顶不是*模式，则直接出栈

最终判定是否p和q都扫描到了尾端。
