### 解题思路
最直接的想法，找出最后一个单词的前一个空格-" "，然后用最后一个字符的下标减去空格下标得到最后一个单词长度，但需注意当字符串末尾有空格时会影响空格搜索以及字符串总长度，因此用trim()方法能删除两端空白。

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        //空格的位置在最后时需要处理,trim()方法删除两端空白
        s = s.trim();
        // lastIndexOf()返回最后的字符ch的索引下标
        int lastspace = s.lastIndexOf(" ");
        return s.length()-1-lastspace;
    }
}
```