### 解题思路
首先拿到最短的一个字符串，然后去匹配，如果有一个不匹配就将要匹配的字符串长度减一，继续匹配
java小菜鸟，欢迎优化

### 代码

```java
class Solution {
   public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }
        int index = 0;
        int minLength = 0;
//拿到最短的字符串以及下表
        for (int i = 0; i < strs.length; i++) {
            if (i == 0) {
                minLength = strs[i].length();
            }
            if (minLength > strs[i].length()) {
                minLength = strs[i].length();
                index = i;
            }
        }
        int length = strs[index].length();
        boolean flag ;
        while (true) {
            flag = true;
//遍历字符串数组进行匹配，一个不匹配就将匹配的字符串减一继续匹配
            for (String str : strs) {
//不存在或者存在的起始位置部位0即不符合条件
                 if (!str.contains(strs[index].substring(0, length))||str.indexOf(strs[index].substring(0,length))!=0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return strs[index].substring(0, length);
            }
            if (length == 1) {
                return "";
            }
            length = length - 1;
        }
    }
}
```