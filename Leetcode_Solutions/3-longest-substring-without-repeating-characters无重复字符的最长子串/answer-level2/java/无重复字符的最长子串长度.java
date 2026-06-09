### 解题思路
就想用一个数据结构存下来目前判定的无重复字符的子串，然后每次读到一个新的字符，都判断这个结构里是不是已经有了这个字符，
代码如下

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int length = 0;
        int max = -1;
        int index = 0;
        // int begin_index = 0;
        Map<Character, Integer> temp = new HashMap<>();
        while (index < s.length()) {
            if (temp.containsKey(s.charAt(index))) {
                // 重复了，
                length = index - temp.get(s.charAt(index));
                int t = temp.get(s.charAt(index));
                temp.clear();
                for (int i = index; i > t; i--) {
                    temp.put(s.charAt(i), i);
                }
                // temp.put(s.charAt(index), index);// 更新下位置，
                //要记住。temp中保存的永远是我正在判断的最长字符串啊，所以要删掉一些，就很麻烦

            } else {
                temp.put(s.charAt(index), index);
                length++;
            }
            index++;
            if (length > max)
                max = length;
        }
        return max == -1 ? 0 : max;
    }
}
```