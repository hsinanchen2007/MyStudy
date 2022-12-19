### 解题思路
默认获取第一个字符串，然后与第二个字符串对比！如果没有重复的前缀出现就一直切割第一个字符串直到出现重复的字符串！随后将提取出来的重复的字符串逐个逐个的对比如果出现不重复就自切割！

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (!(strs != null && strs.length != 0)) {
            return "";
        }
        String str = strs[0];
        for (int i = 1; i < strs.length;i++){
            while(strs[i].indexOf(str) != 0 ){
                str = str.substring(0,str.length()-1);
            }
        }
        return str;
    }
}
```