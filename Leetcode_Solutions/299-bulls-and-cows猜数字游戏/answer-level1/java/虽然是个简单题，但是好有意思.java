### 代码

```java
class Solution {
    public String getHint(String secret, String guess) {
        int len = secret.length();
        int A = 0;//公牛的数量
        int B = 0;//奶牛的数量
        char[] h1 = new char[10];//secret中不是公牛的数字统计
        char[] h2 = new char[10];//guess中不是公牛的数字统计
        char[] sc = secret.toCharArray();
        char[] gc = guess.toCharArray();
        for (int i = 0; i < len; i++) {
            if(sc[i] == gc[i]) A++;
            else {
                int ids = sc[i] - '0';
                int idg = gc[i] - '0';
                h1[ids]++;
                h2[idg]++;
            }
        }
        for (int i = 0; i < 10; i++) {
            //取secret与guess的重叠部分
            B += Math.min(h1[i], h2[i]);
        }
        String ans = A + "A" + B + "B";
        return ans;
    }
}
```