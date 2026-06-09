
![image.png](https://pic.leetcode-cn.com/ca086057dbfec9f41527ce5ddee3b53876317591b67e77f5139f52bd6fa820d6-image.png)

动态规划嘛
先列两个算式：
1. 有效子串 = ( + 有效子子串 + )
2. 有效子串 = 有效子子串 + 有效子子串
3. 最小有效子串 = ()
```
public int longestValidParentheses(String s) {
    boolean a = true;
    int max = 0;
    char[] c = s.toCharArray();
    int[] iss = new int[c.length];
    for(int i = 0;i < c.length - 1;i++) { // 计算最小有效子串
        // if(i + 1 >= c.length) break;
        if (c[i] == '(' && c[i + 1] == ')') {
            iss[i] = 2;
            max = 2;
        }
    }
    do {
        a = false;
        for (int i = 0; i < iss.length; i++) {
            if (iss[i] == 0) continue;
            if (iss[i] > 0 && i - 1 >= 0 && c[i - 1] == '(' && i + iss[i] < c.length && c[i + iss[i]] == ')') {
                iss[i - 1] = iss[i] + 2;
                iss[i] = 0;
                if (max < iss[i - 1]) {
                    max = iss[i - 1];
                }
                a = true;
            } else if (iss[i] > 0 && i + iss[i] < iss.length && iss[i + iss[i]] > 0) {
                int t1 = i + iss[i];
                int t2 = iss[t1];
                iss[i] = iss[i] + t2;
                iss[t1] = 0;
                if (max < iss[i]) {
                    max = iss[i];
                }
                a = true;
            }
        }
    } while (a);
    return max;
}
```
