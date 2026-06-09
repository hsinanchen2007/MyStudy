### 解题思路
普通做法，寻找最大的公共前缀，然后进行字符串的循环生成检测

### 代码

```java
class Solution {
    public static String gcdOfStrings(String str1, String str2) {
        // find the minmal string 
        String temp = "";
        if (str1.length() > str2.length()) {
            temp = str1;
            str1 = str2;
            str2 = temp;
        }
        // find the common max prefix
        int maxMatch = 0;
        for(int i=0;i< str1.length();i++) {
            if(str1.charAt(i)==str2.charAt(i)) {
                String prefix = str1.substring(0,i+1);
                if(matchStr(str1,prefix)) {
                    if(matchStr(str2,prefix)) {
                        maxMatch = i;
                    }
                }
            }
        }
        if(maxMatch == 0) {
            return "";
        } else {
            return str1.substring(0,maxMatch+1);
        }
    }

    private static boolean matchStr(String originString,String pattern) {
        int i=0,j=0;
        while(true) {
            if(i==originString.length()) {
                if(j == 0) {
                    return true;
                } else {
                    return false;
                }
            } 
            if(originString.charAt(i) == pattern.charAt(j)) {
                i ++;
                if(j+1 == pattern.length()) {
                    j=0;
                } else {
                    j++;
                }
            } else {
                return false;
            }
        }
    }

    public static void main(String[] args) {
        System.out.println(gcdOfStrings("ABABAB","ABAB"));
    }
}
```