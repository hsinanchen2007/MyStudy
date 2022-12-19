哈哈哈哈，第一次脑洞与众不同

#### 好了，来讲一下我的思路：
每次遍历长度为k的字符串，判断里面的子串是否都是相同的，（我写了一个静态方法isSame来判断字串是否相同）然后从头到尾进行遍历，就完成了删除长度为k的字符串
但是！！第一次删除后组成的新字符串中，可能又有新的长度为k的相同子串，所以我们所以要写入一个循环中
当什么时候跳出循环呢？？当遍历超过一次，还是没有相同子串时可以删除时，就可以跳出循环了

![image.png](https://pic.leetcode-cn.com/49da12cd5f74d1dbc26945ec14854502fc33f91a1197d8aa831836a4a2c5b1d9-image.png)
```
/**
 * @Author-- Skipper
 */
class Solution {
    public String removeDuplicates(String s, int k) {
        int n = 0;
        while (n < 2) {//循环
            for (int i = 0; i <= s.length() - k; i++) {
                if (k == s.substring(i, i + k).length() && isSame(s.substring(i, i + k))) {
                    s = s.replace(s.substring(i, i + k), "");
                    n = 0;//重置n
                }
            }
            n++;//遍历了一次，n+1
        }
        return s;
    }
    private boolean isSame(String s) {//判断子串是否都相同
        char f = s.charAt(0);
        for (int i = 0; i < s.length(); i++)
            if (s.charAt(i) != f)
                return false;
        return true;
    }
}
```
