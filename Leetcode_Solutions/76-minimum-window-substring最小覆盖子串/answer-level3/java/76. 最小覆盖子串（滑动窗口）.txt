### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String minWindow(String ss, String tt) {
        if(tt.length() == 0){
            return "";
        }

        char[] s = ss.toCharArray();
        char[] t = tt.toCharArray();
        //记录滑动窗口读取的字符个数
        int[] cntS = new int[256];
        //eachN记录的tt中每个字符的个数
        int[] eachN = new int[256];
        //ttNum记录的是tt中有多少个不同的字符
        int ttNum = 0;
        //初始化
        for(int i = 0; i < 256; i++){
            eachN[i] = 0;
        }
        for(char c : t){
            eachN[c]++;
            if(eachN[c] == 1){
                ttNum++;
            }
        }

        int c = 0; //c是两个指针之间已经收集好的tt字符个数
        //最终指针位置
        int ansl = -1, ansr = -1;
        int l,r = 0;
        for(l = 0; l < s.length; l++){
            while(r < s.length && c < ttNum){
                cntS[s[r]]++;
                if(cntS[s[r]] == eachN[s[r]]){
                    c++;
                }
                r++;
            }
            //记录指针位置
            if(c == ttNum){
                if(ansl == -1 || r - l < ansr - ansl){
                    ansl = l;
                    ansr = r;
                }
            }
            //将左指针右移
            cntS[s[l]]--;
            if(cntS[s[l]] == eachN[s[l]] - 1){
                c--;
            }
        }
        //没有找到
        if(ansl == -1){
            return "";
        }
        else{
            return ss.substring(ansl, ansr);
        }
    }
}
```