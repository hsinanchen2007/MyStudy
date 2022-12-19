### 解题思路
此处撰写解题思路
该算法要求将连续相同的字符子串用字母+连续相同字符串个数拼接。
从头到尾依次遍历，直到遇到不同的字母，则拼接当前字符+连续相同字符个数（i-curIndex）。
最后判断转换后字符串与原字符串长度比较，返回两者中较短字符串

### 代码

```java
class Solution {
    public String compressString(String S) {
if (S == null || S.length() == 0) {
            return "";
        }


        StringBuilder result = new StringBuilder();

        char[] inStrArr = S.toCharArray();
        int inStrLen = inStrArr.length;
        int curIndex = 0;
        char curChar = inStrArr[0];
        int  i = curIndex +1;
        for (; i < inStrLen; i++) {
            char c = inStrArr[i];
            if (curChar != c) {
                result.append(curChar).append(i - curIndex);
                curIndex = i;
                curChar = c;
            }

        }


        result.append(curChar).append(i - curIndex);

        return result.toString().length() < inStrLen ? result.toString() : S;
    }
}
```