### 解题思路
有以下注意的点：
1.使用字符串数组记录字符个数
2.使用flag变量控制是否包含该字符串（好像在哪里看到尽量不要使用label这种跳转的....）
3.如果字符串长度大于chars，可以不用比较，直接跳过
4.可以一边遍历目标字符串，一边比较，可能会提前结束，不用再用一个for循环。

### 代码

```java
class Solution {
        public int countCharacters(String[] words, String chars) {
        int len = 0;
        char[] cs = new char[26];
        for (char c : chars.toCharArray()) {
            cs[c - 'a']++;
        }
        for (String str : words) {
            boolean flag = true;
            //如果长度大于chars数组,直接不用比较
            if (chars.length() < str.length()) {
                flag = false;
            } else {
                char[] temp = new char[26];
                for (char t : str.toCharArray()) {
                    temp[t - 'a']++;
                    if(temp[t - 'a'] > cs[t - 'a']) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                len += str.length();
            }
        }
        return len;
        }
}
```