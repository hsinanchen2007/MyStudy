### 解题思路
采用递归形式的二分查找方法。
首先找到中间元素，如果该元素是空字符串，则需要同时从左右两边递归查找是否存在指定元素。
如果中间元素不是空字符串，则需要判断该元素是否是指定元素，这里采用逐一字符对比方法。
逐一对比中间元素的字符是否和指定元素字符相同：
- 如果中间元素字符>指定元素字符，则需要从左半部分递归查找；
- 如果中间元素字符<指定元素字符，则需要从右半部分递归查找；
- 如果中间元素字符和指定元素字符都一样，
    +  并且它们的长度也一样，则中间元素就是我们查找的元素，返回该元素索引
    +  如果中间元素长度>指定元素长度，则向左半部分递归查找；
    +  如果中间元素长度<指定元素长度，则向右半部分递归查找；



### 代码

```java
class Solution {
    public int findString(String[] words, String s) {
        return helper(words, s, 0, words.length - 1);
    }

    public int helper(String[] words, String s, int start, int end) {
        if (start > end) {
            return -1;
        }
        int mid = start + (end - start) / 2;
        String midStr = words[mid];
        if ("".equalsIgnoreCase(midStr)) {
            int lo = helper(words, s, start, mid - 1);
            if (lo != -1) {
                return lo;
            }
            int hi = helper(words, s, mid + 1, end);
            if (hi != -1) {
                return hi;
            }
            return -1;
        } else {
            boolean left = true;
            int length = Math.min(s.length(), midStr.length());
            for (int i = 0; i < length; i++) {
                char sc = s.charAt(i);
                char mc = midStr.charAt(i);
                if (sc > mc) {
                    left = false;
                    break;
                } else if (sc == mc) {
                    if (i == length - 1) {
                        if (s.length() == midStr.length()) {
                            return mid;
                        }
                        left = s.length() < midStr.length();
                    }
                    continue;
                } else {
                    left = true;
                    break;
                }
            }
            if (left) {
                int lo = helper(words, s, start, mid - 1);
                if (lo != -1) {
                    return lo;
                }
            } else {
                int hi = helper(words, s, mid + 1, end);
                if (hi != -1) {
                    return hi;
                }
            }
        }
        return -1;
    }
}
```