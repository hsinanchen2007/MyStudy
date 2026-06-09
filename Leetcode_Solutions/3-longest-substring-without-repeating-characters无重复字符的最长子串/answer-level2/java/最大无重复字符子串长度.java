### 解题思路
此处撰写解题思路
1.取后一个字符，在之前不重复字符数组中检查是否存在
2.存在，则计算之前原无重复字符数组长度，first置为重复字段的位置，last++
3.不存在，则last++
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.equals("")) {
            return 0;
        }

        char[] chars  = s.toCharArray();
        int first = 0;
        int last = 0;
        int max = 1;

        int sel = last + 1;
        
        while (sel < chars.length) {
            int index = checkin(chars[sel], chars, first, last);
            if (index < 0) {
                max = Math.max(max, last - first + 1);
                last ++;
                sel = last + 1;
                max = Math.max(max, last - first + 1);
            } else {
                max = Math.max(max, last - first + 1);
                first = index + 1;
                last = last + 1;
                sel = last + 1;
            }
            
        }
        return max;
    }

    public int checkin(char sel, char[] chars, int first, int last) {
        for (int i = first; i <= last; i++) {
            if (sel == chars[i]) {
                return i;
            }
        }
        return -1;
    }
}
```