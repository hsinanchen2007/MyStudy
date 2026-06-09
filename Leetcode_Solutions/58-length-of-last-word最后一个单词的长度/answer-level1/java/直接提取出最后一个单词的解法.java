由题意易得，当所给的字符串s为空格组成的字符串的时候，不存在最后一个单词。
由于单词之间以空格分隔开，因此可以按照 " " 字符来把原字符串分割为字符串数组，并直接返回数组最后一个元素的长度。

```
class Solution {
    public int lengthOfLastWord(String s) {
        int ans = 0;
        if(s.trim().isEmpty() == true)
            ans = 0;
        else {
            String[] str = s.split(" ");
            ans = str[str.length - 1].length();
        }
        return ans;
    }
}
```
