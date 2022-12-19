### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        String str = "1";
        for(int i = 1; i < n; i++) {
            char[] strs = str.toCharArray();
            int times = 1;
            String str1 = "";
            for(int j = 0; j < strs.length; j++) {
                if(strs.length == 1){
                    str1 = str1 + (times +""+ strs[j]);
                    break;
                }
                if(j == strs.length-1){
                    str1 = str1 + (times +""+ strs[j]);
                    break;
                }
                if(strs[j] == strs[j+1]){
                    times++;
                }else{
                    str1 = str1 + (times +""+ strs[j]);
                    times = 1;
                }
            }
            str = str1;
            str1 = "";
        }
        return str;
    }
}
```