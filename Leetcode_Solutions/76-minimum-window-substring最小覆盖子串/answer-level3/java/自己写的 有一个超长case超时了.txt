### 解题思路
注释掉的代码是对的 只是有一个超时的
复制了powcai大神的代码 通过了
万能模版+解法滑动窗口问题

### 代码

```java
import java.util.HashMap;
import java.util.Map;
import java.lang.StringBuilder;
class Solution {
    public String minWindow(String s, String t) {
        //波菜大神的代码
        Map<Character, Integer> lookup = new HashMap<>();
        for (char c : s.toCharArray()) lookup.put(c, 0);
        for (char c : t.toCharArray()) {
            if (lookup.containsKey(c)) lookup.put(c, lookup.get(c) + 1);
            else return "";
        }
        int start = 0;
        int end = 0;
        int min_len = Integer.MAX_VALUE;
        int counter = t.length();
        String res = "";
        while (end < s.length()) {
            char c1 = s.charAt(end);
            if (lookup.get(c1) > 0) counter--;
            lookup.put(c1, lookup.get(c1) - 1);
            end++;
            while (counter == 0) {
                if (min_len > end - start) {
                    min_len = end - start;
                    res = s.substring(start, end);
                }
                char c2 = s.charAt(start);
                if (lookup.get(c2) == 0) counter++;
                lookup.put(c2, lookup.get(c2) + 1);
                start++;
            }
        }
        return res; 
        /****** 解法是对的 但是有一个case超时
        //双指针 + 滑动窗口 + 思路
        //滑动窗口左区间
        int left  = 0;
        //滑动窗口右区间
        int right = 0; 

        //主串长度
        int sLen  = s.length(); 

        //子串长度
        int tLen  = t.length();

        //子串长度大于主串长度
        if (sLen < tLen) {
            return "";
        }

        //设置map计数
        Map<Character, Integer> hash = new HashMap<Character, Integer>();

        //保存字串的map计数
        Map<Character, Integer> childHash = new HashMap<Character, Integer>();
        for (int i = 0; i < tLen; i++) {
            if (childHash.containsKey(t.charAt(i))) {
                childHash.put(t.charAt(i), childHash.get(t.charAt(i)) + 1);
            } else {
                childHash.put(t.charAt(i), 1);
            }
        }

        //保存子串的值
        String child = s;

        //是否是第一次
        boolean flag = false;

        //双指针模版
        a: while (right < sLen) {
            //滑动右窗口
            if (hash.containsKey(s.charAt(right))) {
                hash.put(s.charAt(right), hash.get(s.charAt(right)) + 1);
            } else {
                hash.put(s.charAt(right), 1);
            }
            right++;
            
            //判断是否有效(窗口是否包含子串)
            while (right - left >= tLen) {
                for (int i = 0; i < tLen;  i++) {
                    if (!hash.containsKey(t.charAt(i))) {//不包含这个字符串 直接continue
                        continue a;
                    }
                    if (hash.get(t.charAt(i)) < childHash.get(t.charAt(i))) {
                        continue a;
                    }
                }

                //找到了 更新最小值
                flag = true;
                child = (child.length() > (right - left)) ? s.substring(left, right) : child;
                //左节点的
                hash.put(s.charAt(left), hash.get(s.charAt(left)) - 1);
                left++;
            }
        }

        return flag ? child : "";
        ********/
    }
}
```