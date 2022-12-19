### 解题思路
有点动态规划的样子 但完全不是
就是把长度l作为每次循环的次数

### 代码

```java
class Solution {
        public static int countLetters(String S) {
        char[] s=S.toCharArray();
        int sum=s.length;
        for(int l=2;l<=s.length;l++) {
            for(int i=0;i<=s.length-l;i++) {
                for(int j=i+1;j<=i+l-1;j++) {
                    if(s[i]!=s[j]) break;
                    if(s[i]==s[j]&&j==i+l-1) sum++;
                }
            }
        }
        return sum;
    }
}
```