### 分析
新建一个needs[128] 用来统计t中每个字符出现次数，新建一个 window[128]用来统计滑动窗口中每个字符出现次数。首先统计出T中每个字母出现的次数. 新建两个变量left和right分别用来表示滑动窗口的左边和右边。新建一个变量count来表示目前窗口中已经找到了多少个字符。
以S = "ADOBECODEBANC", T = "ABC"为例，然后按照如图所示的规律滑动窗口。
![图片.png](https://pic.leetcode-cn.com/e724fedf218ab040da373452d89c457f33018909cca29fe5c3202bf01d42e26a-%E5%9B%BE%E7%89%87.png)
即可得出最小子串的长度为4，最小子串为"BANC"。
### 代码
```java
public static String minWindow(String s, String t) {
        if (s == null || s == "" || t == null || t == "" || s.length() < t.length()) {
            return "";
        }
        //用来统计t中每个字符出现次数
        int[] needs = new int[128];
        //用来统计滑动窗口中每个字符出现次数
        int[] window = new int[128];

        for (int i = 0; i < t.length(); i++) {
            needs[t.charAt(i)]++;
        }

        int left = 0;
        int right = 0;

        String res = "";

        //目前有多少个字符
        int count = 0;

        //用来记录最短需要多少个字符。
        int minLength = s.length() + 1;

        while (right < s.length()) {
            char ch = s.charAt(right);
            window[ch]++;
            if (needs[ch] > 0 && needs[ch] >= window[ch]) {
                count++;
            }

            //移动到不满足条件为止
            while (count == t.length()) {
                ch = s.charAt(left);
                if (needs[ch] > 0 && needs[ch] >= window[ch]) {
                    count--;
                }
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    res = s.substring(left, right + 1);

                }
                window[ch]--;
                left++;

            }
            right++;

        }
        return res;
    }
```