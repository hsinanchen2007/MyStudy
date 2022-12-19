### 解题思路
小白分享：
主要是对输入的特殊情况一定要进行判断，我开始错了好多遍都是因为没有对输入的特殊情况进行判断，ε=(´ο｀*)))唉

### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        if ((word1 == null || word1.equals("")) && (word2 == null || word2 .equals(""))) {
            return 0;
        }
        if (word1 == null || word1.equals("")) {
            return word2.length();
        }
        if (word2 == null || word2 .equals("")) {
            return word1.length();
        }

        char[] w1c = word1.toCharArray();
        char[] w2c = word2.toCharArray();
        int l1 = word1.length();
        int l2 = word2.length();
        int[][] df = new int[l1][l2];
        if (w1c.length > 0 && w2c.length > 0) {
            if (w1c[0] == w2c[0]) {
                df[0][0] = 0;
            } else {
                df[0][0] = 1;
            }
            for (int i = 1; i < l2; i++) {
                if (w1c[0] == w2c[i]) {
                    df[0][i] = i;
                } else {
                    df[0][i] = df[0][i-1] + 1;
                }
            }
            for (int i = 1; i < l1; i++) {
                if (w1c[i] == w2c[0]) {
                    df[i][0] = i;
                } else {
                    df[i][0] = df[i-1][0] + 1;
                }
            }
            for (int i = 1; i < l1; i++) {
                for (int j = 1; j < l2; j++) {
                    if (w1c[i] == w2c[j]) {
                        df[i][j] = df[i-1][j-1];
                    } else {
                        df[i][j] = Math.min(Math.min(df[i-1][j],df[i][j-1])+1,df[i-1][j-1] +1);
                    }
                }
            }
            return df[l1-1][l2-1];
        }
        return 0;
    }
}
```