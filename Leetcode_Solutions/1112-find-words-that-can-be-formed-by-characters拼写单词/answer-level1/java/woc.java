### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int num = words.length;
        int num2 = chars.length();
        int count = 0;
        for (int i = 0; i < num; i++) {
            int n = 0;
            char[] s = chars.toCharArray();
            for (int j = 0; j < words[i].length(); j++) {
                if(s.length < words[i].length())
                    continue;
                for (int k = 0; k < num2; k++) {
                    if (words[i].toCharArray()[j] == s[k]) {
                        n++;
                        s[k] = '0';
                        break;
                    }
                }
                if (n == words[i].length())
                    count += words[i].length();
            }
        }
        return count;
        }
}
```![QQ图片20200317215831.png](https://pic.leetcode-cn.com/981e8b5f45fbc57482031a844ad35973edb74b754dda3a4a47bde673243df457-QQ%E5%9B%BE%E7%89%8720200317215831.png)
