### 解题思路
观察可以得到如果两个字符串是混淆可以得到的，那么长度必然相等，各个字符出现的次数相等。
而一个混淆字符串可以找到混淆的中点，中点前对应的字符出现次数相等，因此不断递归统计字符出现次数即可。

### 代码

```java
    class Solution {
        public boolean isScramble(String s1, String s2) {
            if(s1.length()!=s2.length()||s1.length()==0)
                return false;
            if(s1.equals(s2))
                return true;
            int[] c2f = new int[128];
            int[] c2b = new int[128];
            int sf = 0,sb = 0;
            for (int i = 0; i < s1.length()-1; i++) {
                sf += (c2f[s1.charAt(i)]==0)?1:0;
                sf += (c2f[s2.charAt(i)]==0)?1:0;
                c2f[s1.charAt(i)]++;
                c2f[s2.charAt(i)]--;
                sf += (c2f[s1.charAt(i)]==0)?-1:0;
                sf += (c2f[s2.charAt(i)]==0)?-1:0;
                sb += (c2b[s1.charAt(i)]==0)?1:0;
                sb += (c2b[s2.charAt(s1.length()-i-1)]==0)?1:0;
                c2b[s1.charAt(i)]++;
                c2b[s2.charAt(s2.length()-i-1)]--;
                sb += (c2b[s1.charAt(i)]==0)?-1:0;
                sb += (c2b[s2.charAt(s1.length()-i-1)]==0)?-1:0;
                if(sf==0&&isScramble(s1.substring(0,i+1),s2.substring(0,i+1))&&isScramble(s1.substring(i+1),s2.substring(i+1))){
                    return true;
                }
                if (sb==0&&isScramble(s1.substring(0,i+1),s2.substring(s2.length()-i-1))&&isScramble(s1.substring(i+1),s2.substring(0,s2.length()-i-1))){
                    return true;
                }
            }
            return false;
        }
    }
```