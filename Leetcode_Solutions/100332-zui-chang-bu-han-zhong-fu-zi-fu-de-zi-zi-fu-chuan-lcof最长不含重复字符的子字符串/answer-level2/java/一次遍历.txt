### 解题思路
- 使用临时数组存储每个字符出现的位置
- 使用left存储当前重复字符的前一个的位置
- 使用sublen存储子串的长度
当字符未重复时，则子串长度加一，当字符重复时，left的位置为当前重复字符的前一个的位置，子串长度则为当前位置减去left加上当前字符长度1。最后比较目前子串长度是否最大，且存储当前字符的位置。

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len = s.length();
        int left = 1;
        int sublen = 0;
        int max = 0;
        int[] chars = new int[128];
        for(int i = 0 ; i < len; i++){
            int index = (int)s.charAt(i);
            if(chars[index] != 0){
                left = (left > chars[index]?left:chars[index]);
                sublen = i - left + 1;
            }else{
                sublen++;
            }
            if(sublen > max){
                max = sublen;
            }
            chars[index] = i+1;
        }
        return max;
    }
}
```