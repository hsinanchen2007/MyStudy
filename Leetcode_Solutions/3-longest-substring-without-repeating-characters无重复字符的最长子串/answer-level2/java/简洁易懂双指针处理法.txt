### 解题思路
双指针解法：
    i 遍历字符串，
    rIndex 记录重复字符的位置
    result 记录子串最长值
    出现重复（从重复字符下一位字符开始比较是否重复），更新 rIndex的 值。
    例子：
               p    e   w   k   w   e
          i    0    1   2   3   4   5
     rIndex    0    0   0   0   3   3 
     result    1    2   3   4   4   4
    在 i = 3 时， result = 3 - 0 + 1 = 4
    如上 在 i = 4 时，出现重复，即 i 的值 大于首次出现 w 的索引值。更新rIndex的值为3，即首次出现 w 的索引值+1
    result值比较（取更大值）更新
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int i = 0;
        int rIndex = 0;
        int result = 0;
        while(i < s.length()){
            int pos = s.indexOf(s.charAt(i), rIndex);
            //出现重复
            if(pos < i){
                rIndex = pos + 1;
            }
            result = result > (i - rIndex + 1) ? result : (i - rIndex + 1);
            i++;
        }
        return result;
    }
}
```