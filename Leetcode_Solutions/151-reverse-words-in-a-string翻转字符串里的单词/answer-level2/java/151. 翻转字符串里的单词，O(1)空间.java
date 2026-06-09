### 解题思路
#### 方法一（用 C 写可以 O(1) 空间，原地翻转）
1、去掉 s 头尾和中间多余的空格
```
"  hello world!  " -> "hello world!"
"a good   example" -> "a good example"
```
2、反转整个字符串 s，得到字符串 s1
```
"hello world!" -> "!dlrow olleh"
"a good example" -> "elpmaxe doog a"
```
3、依次反转 s1 的每个单词
```
 "!dlrow olleh" -> "world! hello"
"elpmaxe doog a" -> "example good a"
```
**用 char[] 处理。(4ms C风格)，但因为 java 的 s.toCharArray() 会拷贝一份，所以有点慢。用 C 写出来应该会快不少**

#### 方法二（用 StringBuilder 最快可以 3ms）
**从后往前**扫描字符串，依次把扫描到的单词连接起来。
拿 "a good   example" 举例。
1、扫描到 "example"
```
"a good   example" 
stringBuilder <- "example"
```
2、扫描到 "good"
```
"a good   example" 
stringBuilder <- "example good"
```

3、扫描到 "a"
```
"a good   example" 
stringBuilder <- "example good a"
```

### 方法一代码（4ms/14ms）
**以下两个代码没有任何本质区别**
1. 直接用 char[] 处理。(4ms C风格)
2. 用 StringBuilder 处理。(14ms StringBuilder)
```java []
class Solution {
    public String reverseWords(String s) {
        return reverseWords(s.toCharArray());
    }

    /**
     * 1、去掉 s 头尾和中间多余的空格
     * 2、反转整个字符串 s，得到字符串 s1
     * 3、依次反转 s1 的每个单词
     *
     * @param s
     * @return
     */
    public String reverseWords(char[] s) {
        int N = trimString(s);

        // 反转整个字符串 s，得到字符串 s1
        reverseString(s, 0, N - 1);

        // 依次反转 s1 的每个单词
        int l = 0;
        int r = -1;
        for (int i = 0; i < N; ++i) {
            if (s[i] == ' ') {
                if (r - l >= 0) {
                    reverseString(s, l, r);
                }
                l = i + 1;
                r = i;
            } else {
                ++r;
            }
        }
        if (r - l >= 0) {
            reverseString(s, l, r);
        }
        return new String(s, 0, N);
    }

    /**
     * 去掉字符串多余空格
     *
     * @param s
     * @return 处理后的字符串大小
     */
    public int trimString(char[] s) {
        int N = 0;
        int k = 0;
        while (k < s.length && s[k] == ' ') {
            ++k;
        }
        for (; k < s.length; ++k) {
            if (k > 0 && s[k] == ' ' && s[k - 1] == ' ') {
                continue;
            }
            s[N] = s[k];
            ++N;
        }
        while (N > 1 && s[N - 1] == ' ') {
            --N;
        }
        return N;
    }

    /**
     * 反转字符串的区间 [l, r]
     *
     * @param s
     * @param l
     * @param r
     */
    public void reverseString(char[] s, int l, int r) {
        int N = r - l + 1;
        int midPos = N / 2;
        for (int i = 0; i < midPos; ++i) {
            char ch1 = s[l + i];
            char ch2 = s[r - i];
            s[l + i] = ch2;
            s[r - i] = ch1;
        }
    }
}
```
```java []
  public String reverseWords(String s) {
        StringBuilder stringBuilder = trimString(s);

        // 反转整个字符串 s，得到字符串 s1
        reverseString(stringBuilder, 0, stringBuilder.length() - 1);

        // 依次反转 s1 的每个单词
        int l = 0;
        int r = -1;
        for (int i = 0; i < stringBuilder.length(); ++i) {
//            System.out.println(i + ": {" + s[i] + "}, [l, r]=" + l + ", " + r);
            if (stringBuilder.charAt(i) == ' ') {
                if (r - l >= 0) {
                    reverseString(stringBuilder, l, r);
                }
                l = i + 1;
                r = i;
            } else {
                ++r;
            }
        }
        if (r - l >= 0) {
            reverseString(stringBuilder, l, r);
        }
        return stringBuilder.toString();
    }

    /**
     * 去掉字符串多余空格
     *
     * @param s
     * @return 处理后的字符串大小
     */
    public StringBuilder trimString(String s) {
        StringBuilder stringBuilder = new StringBuilder();
        int N = 0;
        int k = 0;
        while (k < s.length() && s.charAt(k) == ' ') {
            ++k;
        }
        for (; k < s.length(); ++k) {
            if (k > 0 && s.charAt(k) == ' ' && s.charAt(k - 1) == ' ') {
                continue;
            }
            stringBuilder.append(s.charAt(k));
            ++N;
        }

        while (N > 1 && stringBuilder.charAt(N - 1) == ' ') {
            --N;
        }
        stringBuilder.setLength(N);
        return stringBuilder;
    }

    /**
     * 反转字符串的区间 [l, r]
     *
     * @param s
     * @param l
     * @param r
     */
    public void reverseString(StringBuilder s, int l, int r) {
        int N = r - l + 1;
        int midPos = N / 2;
        for (int i = 0; i < midPos; ++i) {
            char ch1 = s.charAt(l + i);
            char ch2 = s.charAt(r - i);
            s.setCharAt(l + i, ch2);
            s.setCharAt(r - i, ch1);
        }
    }
```

### 方法二代码（8ms/3ms）
** 以下代码没有本质区别 **
1. 单独用一个 StringBuilder 记录扫描到的单词，8ms
2. 用两个指针记录扫描到的单词 [l, r），3ms

```java []
class Solution {
       public String reverseWords(String s) {
        StringBuilder stringBuilder = new StringBuilder();
        StringBuilder word = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; --i) {
            char ch = s.charAt(i);
            if (ch == ' ') {
                if (word.length() > 0) {
                    if (stringBuilder.length() > 0) {
                        stringBuilder.append(' ');
                    }
                    stringBuilder.append(word.reverse());
                    word.setLength(0);
                }
            } else {
                word.append(ch);
            }
        }
        if (word.length() > 0) {
            if (stringBuilder.length() > 0) {
                stringBuilder.append(' ');
            }
            stringBuilder.append(word.reverse());
        }

        return stringBuilder.toString();
    }
}
```
```java []
    public String reverseWords(String s) {
        StringBuilder stringBuilder = new StringBuilder();
        int l = s.length();
        int r = s.length();
        for (int i = s.length() - 1; i >= 0; --i) {
            char ch = s.charAt(i);
            if (ch == ' ') {
                if (r - l > 0) {
                    if (stringBuilder.length() > 0) {
                        stringBuilder.append(' ');
                    }
                    stringBuilder.append(s.substring(l, r));
                }
                r = i;
                l = i;
            } else {
                --l;
            }
        }
        if (r - l > 0) {
            if (stringBuilder.length() > 0) {
                stringBuilder.append(' ');
            }
            stringBuilder.append(s.substring(l, r));
        }

        return stringBuilder.toString();
    }
```