### 解题思路
字符数组计数
整理拍照为计数数组
比较、剪枝
记录结果
26 小写字母个数， 97 a， -32 A - a， -6 Z - a

### 代码

```java
class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        String min = "";
        int len = 20;
        int[] kc = new int[26];

        for(int i = 0; i < licensePlate.length(); i++){
            int index = licensePlate.charAt(i) - 97;
            if(0 <= index && index < 26)//避免正则匹配以及转小写
                kc[index]++;
            else if(-32 <= index&& index < -6)
                kc[index + 32]++;
        }
        int[][] ws = new int [words.length][];
        for(int i = 0; i < words.length; i++){
            int [] t = new int [26];
            for(int j = 0; j < words[i].length(); j++){
                t[words[i].charAt(j) - 97]++;
            }
            ws[i] = t;
        }

        for(int i = 0; i < ws.length; i++){
            boolean f = true;
            int [] t = ws[i];
            for(int j = 0; j < 26; j++){
                if(t[j] < kc[j]){//剪枝
                    f = false;
                    break;
                }
            }
            if(f && words[i].length() < len){
                min = words[i];
                len = words[i].length();
            }
        }
        return min;
    }
}
```