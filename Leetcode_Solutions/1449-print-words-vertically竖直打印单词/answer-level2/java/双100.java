### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/de36be7017ca8e4a937e05ae3e0f10cecd4b4419d4c9e9ac7bea25fd1f1f25e1-image.png)

首先分割字符串s，将分割后的每个单词存到一个String数组里面，然后找出单词的最大长度记为maxLen，代表
竖直排列单词后单词的数量，也就是最后返回的List的长度。然后定义一个String变量（其实StringBuilder会
更好，效率更高），将所有单词的第i个字母依次添加到String变量里面，遍历所有单词后，可能有空格添加到
String变量的末尾，去掉即可（统计末尾空格的数量，然后选取String变量的子串），然后添加到List里面。

### 代码

```java
class Solution {
    public List<String> printVertically(String s) {
        List<String> list = new ArrayList<>();
        if (s == null) {
            return list;
        }
        String c [] = s.split(" ");
        int maxLen = 0;
        for (int i = 0; i < c.length; i++) {
            maxLen = c[i].length() > maxLen ? c[i].length() : maxLen;
        }
        for (int i = 0; i < maxLen; i++) {
            String t = "";
            for (int j = 0; j < c.length; j++) {
                if (i < c[j].length()) {
                    t = t + c[j].charAt(i);
                } else {
                    t = t + ' ';
                }
            }
            int k;
            for (k = t.length() - 1; k > 0; k--) {
                if (t.charAt(k) != ' ') {
                    break;
                }
            }
            list.add(t.substring(0, k + 1));
        }
        return list;
    }
}
```