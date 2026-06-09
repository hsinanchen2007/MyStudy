### 解题思路

- 使用Stack存储字符串中剩余的字符并equals
- 双指针法，从字符串的最后一位往前，记录#号的个数，一个#号之后紧随的一个字符要删掉，之后记录下剩下的下标，并比较两个字符串对应位置的字符是否相同，如果相同，继续循环，如果不同，返回false。

### 代码

```java
class Solution {

        public boolean backspaceCompare(String S, String T) {
        int i = S.length() - 1; // String s index
        int j = T.length() - 1; // String t index

        int backS = 0; // String s delete char numbers
        int backT = 0; // String t delete char numbers

        while (i >= 0 || j >= 0) {

            while (i >= 0) {
                if (S.charAt(i) == '#') {backS ++; i--;}
                else if (backS > 0) {backS --; i--;}
                else break;
            }

            while (j >= 0) {
                if (T.charAt(j) == '#') {backT ++; j--;}
                else if (backT > 0) {backT --; j--;}
                else break;
            }

            if (i >= 0 && j >= 0 && S.charAt(i) != T.charAt(j)) return false;

            if (i >= 0 != j >= 0) return false;

            i--;
            j--;

        }

        return true;
    }

    public boolean backspaceCompareNew(String S, String T) {
        return simpleStr(S).equals(simpleStr(T));
    }

    private Stack<Character> simpleStr(String S) {
        Stack<Character> s1 = new Stack<>();
        for (int i = 0; i < S.length(); i++) {
            s1.push(S.charAt(i));
            if (S.charAt(i) == '#') {
                if (!s1.empty()) s1.pop();
                if (!s1.empty()) s1.pop();
            }
        }
        return s1;
    }
}
```