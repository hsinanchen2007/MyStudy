### 解题思路
此处撰写解题思路
1. 首先简单了解两个函数：**indexOf() **方法是返回某个指定的字符串值在字符串中首次出现的位置。
                   ** substring(int beginIndex, int endIndex)**方法是返回一个新字符串，
                它是此字符串的一个子字符串。该子字符串从指定的 beginIndex 处开始，
                endIndex:到指定的 endIndex-1处结束。
2. 将第一个字符串作为prefix。
3. 然后拿prefix与其他数组进行比较。
4. 如果indexOf返回的不是0，说明字符串的第一个字符没有匹配上就不可能是公共前缀。
5. 通过subString函数不断将prefix的最后一个字符砍掉，长度继续减少，再进行匹配。
6. 直到indexOf返回的是0，说明匹配上了。

该方法是受题解视频启发。
### 代码

```java
class Solution {
   public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";
        String prefix = strs[0];
        for (String s :
                strs) {
            while(s.indexOf(prefix) !=0){
                prefix = prefix.substring(0,prefix.length()-1);
            }
        }
        return  prefix;
    }
}
```