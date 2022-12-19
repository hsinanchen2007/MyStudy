递归，执行用时104ms，内存消耗46MB
```
class Solution {
    public static String countAndSay(int n) {
        //递归
        String finalString = "";
        if(n==1) return "1";
        else {
            String midResult = countAndSay(n-1);
            int i = 0, j = 0;
            for(; i < midResult.length();) {
                //如果 j+1 大于等于midResult的长度，说明j指向的下一位置字符为空，
                //所以此时循环结束，共有 j-i+1 个i位置的字符
                if(j + 1 >= midResult.length()) {
                    finalString = finalString + (j - i + 1) + midResult.charAt(i);
                    break;
                }
                //如果 j 位置的下个字符不为空，
                //则 j++ 后继续循环查看 j 的下个字符是否于 i 位置的字符相等
                else if(midResult.charAt(i) == midResult.charAt(j+1)) j++;
                // i 位置字符于 j+1 位置不等，说明此时只有 j-i+1 个 i 位置字符
                else {
                    finalString = finalString + (j - i + 1) + midResult.charAt(i);
                    System.out.println(finalString);
                    i = j + 1;
                    j = i;
                }
            }
        }
        return finalString;
    }
}
```


正则匹配，执行用时：33ms，内存消耗47.4MB
```
import java.util.regex.Matcher;
import java.util.regex.Pattern;
class Solution {
    public static String countAndSay(int n) {
        /**
        正则匹配法：匹配1-9的一个重复多次的数字
        \\d表示匹配一个数字，\\1表示由转义括号捕获的字符，*表示任意个数
        **/
        String str = "1";
        String pattern = "(\\d)\\1*";
        Pattern r = Pattern.compile(pattern);
        for(int i = 0; i < n - 1; i++) {
            String tmpStr = "";
            Matcher m = r.matcher(str);
            while (m.find()) {
                tmpStr  = tmpStr + (m.end()-m.start()) + str.charAt(m.start());
            }
            str = tmpStr;
            //System.out.println("stringBuffer: "+str);
        }
        return str;
    }
}
```
