### 解题思路
1.split方法，将字符串分成字符串数组
2.reverse方法，快速翻转字符串
3.trim方法，去掉首尾多余空格

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String[] strings = s.split(" ");
        StringBuffer stringBuffer = new StringBuffer();
        for (int i = 0; i < strings.length; i++) {
            // 反转字符串利用StringBuffer的reverse方法
            stringBuffer.append(new StringBuffer(strings[i]).reverse().toString() + " ");
        }
        //去除最后一个空格
        return stringBuffer.toString().trim();
    }
}
```