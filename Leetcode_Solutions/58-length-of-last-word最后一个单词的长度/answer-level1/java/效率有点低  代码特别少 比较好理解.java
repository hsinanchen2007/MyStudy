先以“ ”为分割符分割成数组 直接返回字符串数组中最后一个元素的长度即可


```
代码块
class Solution {
    public int lengthOfLastWord(String s) {

        String[] strings = s.split(" ");
        if (strings.length == 0){
            return 0;
        }
        return strings[strings.length - 1].length();

    }
}
```
