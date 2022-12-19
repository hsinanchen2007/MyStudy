### 解题思路
非常古朴的思路，首先去掉所有“-”，在组成新的字符串的基础上，确定第一个“-”应该放在多少个字符之后，这里采用变换后的字符串长度对K取余，即可得到当前位置，后面的依次按照K个为一组进行分组。

### 代码

```java
class Solution {
    public String licenseKeyFormatting(String S, int K) {
        if(S.equals("-")) {
            return "";
        }
        if(S.length()==1) {
            return S.toUpperCase();
        }
        
        String SS = "";
       for(int i = 0;i<S.length();i++) {
           if(S.charAt(i)!='-') {
               SS = SS+S.charAt(i);
           }
       }
        S = SS.toUpperCase();
        SS = "";
        int i = 0;
        if(S.length()%K==0) {
            for(int j = 0;j<S.length();j++) {
                SS = SS+S.charAt(j);
                if(j==S.length()-1) {
                    break;
                }
                if((j+1)%K==0) {
                    SS = SS+'-';
                }
            }
            return SS;
        }


        for(i = 0;i<S.length()%K;i++) {
            SS = SS+S.charAt(i);
        }
        SS = SS+'-';
        for(int j = 0;j<S.length()-i;j++) {
            SS=SS+S.charAt(j+i);
            if(j==S.length()-1-i) {
                break;
            }
            if((j+1)%K==0) {
                SS = SS+'-';
            }
        }
        return SS;
    }
}
```