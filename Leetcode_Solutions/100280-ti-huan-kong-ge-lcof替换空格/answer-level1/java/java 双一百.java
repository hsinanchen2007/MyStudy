![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/337e56d625c040f9627a607906d32e9ef8901ac8c45f77877f3187a61114a1e7-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        char[] chars = s.toCharArray();
        int num = 0;//记录空格的总数
        for (char aChar : chars) {
            if (aChar == ' ') {
                num++;
            }
        }
        char[] res = new char[s.length() + num * 2];
        int j = res.length - 1;//一个指针
        for (int i = s.length() - 1; i >= 0; i--) {
            if (chars[i] != ' ') {
                res[j] = chars[i];
                j--;
            } else {// 是空格
                res[j] = '0';
                res[j - 1] = '2';
                res[j - 2] = '%';
                j -= 3;
            }
        }
        return new String(res);
    }
}
```