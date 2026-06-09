### 解题思路
1.split截串
2.新建一个nstr数组保存非空串
3.Arrays.copyof截取非null部分
4.用Stringbuilder对nstr数组进行拼串
5.优化思路：应该可以在str数组上原地进行变换以节省额外给nstr数组开辟的空间
### 代码

```java
public class Solution {
    public String reverseWords(String s) {
        String[] strs = s.split(" ");
        /*处理掉strs中的空串*/
        String [] nstrs = new String[strs.length];
        int count = 0 ;
        for (int i = 0; i <strs.length ; i++) {
            if (strs[i].equals("")){
                continue;
            }
            nstrs[count++] = strs[i];
        }
        String[] strings = Arrays.copyOf(nstrs, count);
        for (int i = 0; i <count/2 ; i++) {
            String temp = strings[i];
            strings[i] = strings[count-1-i];
            strings[count-1-i]  = temp ;
        }
        StringBuilder stringBuilder = new StringBuilder();
        for ( String str : strings ) {
            stringBuilder.append(str).append(" ");
        }
        return stringBuilder.toString().trim();
    }
}
```