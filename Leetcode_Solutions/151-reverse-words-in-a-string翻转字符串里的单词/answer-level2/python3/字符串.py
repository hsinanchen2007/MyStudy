## 思路:

思路一: 使用 `split`和`reverse`

```python []
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])
```



```python []
class Solution {
    public String reverseWords(String s) {
        String[] words = s.trim().split(" +");
        Collections.reverse(Arrays.asList(words));
        return String.join(" ", words);
    }
}
```

思路二:  一种没有用`split` 和`reverse`的方法,参考链接[^1]

分三步:

1. 先翻转整个数组
2. 再翻转单个单词
3. 清除多余空格

```python []
class Solution:
    def reverseWords(self, s: str) -> str:
        s = list(s)
        n = len(s)
        #print(s)
        
        # 翻转数组
        def reverse(s, i, j):
            while i < j:
                s[i], s[j] = s[j], s[i]
                i += 1
                j -= 1

        # 翻转单个单词
        def word_reverse(s):
            # 用双指针找到一个单词
            i = 0
            j = 0
            while i < n:
                # 找到一个单词首字母
                while i < n and s[i] == " ":
                    i += 1
                j = i
                # 找到一个单词末位置
                while j < n and s[j] != " ":
                    j += 1
                reverse(s, i, j - 1)
                i = j

        # 清除多余空格
        def clean_space(s):
            i = 0
            j = 0
            while j < n:
                # 找到一个单词
                while j < n and s[j] == " ":
                    j += 1
                # 单词朝前移
                while j < n and s[j] != " ":
                    s[i] = s[j]
                    i += 1
                    j += 1
                # 移动下一个单词
                while j < n and s[j] == " ":
                    j += 1
                if j < n:
                    s[i] = " "
                    i += 1
            return "".join(s[:i])

        reverse(s, 0, n - 1)
        #print(s)
        word_reverse(s)
        #print(s)
        return clean_space(s)
```



```java []
class Solution {
    public String reverseWords(String s) {
        if (s == null) return null;
        char[] s_arr = s.toCharArray();
        int n = s_arr.length;
        // 翻转这个数组
        reverse(s_arr, 0, n - 1);
        System.out.println(new String(s_arr));
        // 翻转每个单词
        word_reverse(s_arr, n);
        System.out.println(new String(s_arr));
        // 去除多余空格
        return clean_space(s_arr, n);
    }

    private void reverse(char[] s_arr, int i, int j) {
        while (i < j) {
            char t = s_arr[i];
            s_arr[i++] = s_arr[j];
            s_arr[j--] = t;
        }
    }

    private void word_reverse(char[] s_arr, int n) {
        int i = 0;
        int j = 0;
        while (j < n) {
            // 找到第一个首字母
            while (i < n && s_arr[i] == ' ') i++;
            j = i;
            // 末位置
            while (j < n && s_arr[j] != ' ') j++;
            reverse(s_arr, i, j - 1);
            i = j;
        }
    }

    private String clean_space(char[] s_arr, int n) {
        int i = 0;
        int j = 0;
        while (j < n) {
            while (j < n && s_arr[j] == ' ') j++;
            while (j < n && s_arr[j] != ' ') s_arr[i++] = s_arr[j++];
            while (j < n && s_arr[j] == ' ') j++;
            if (j < n) s_arr[i++] = ' ';
        }
        return new String(s_arr).substring(0, i);
    }
}
```





[^1]: <https://leetcode.com/problems/reverse-words-in-a-string/discuss/47781/Java-3-line-builtin-solution>