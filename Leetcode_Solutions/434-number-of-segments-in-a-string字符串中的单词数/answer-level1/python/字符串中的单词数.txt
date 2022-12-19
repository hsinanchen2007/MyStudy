#### 方法一：使用语言内置函数 【通过】

**直觉**

在执行效率不如代码可读性重要的情况下，使用语言内置的函数解决问题更好些。

**算法**

本问题有一些边缘情况需要考虑，至少在Java中如此。首先，开头的一个或多个空格会导致 `split` 函数在字符串开头产生一个错误的 `""`，因此我们使用内置的 `trim` 函数来移除这些空格。其次，如果结果为空字符串，可以直接输出  `0`。由于 `split` 函数的下述特性，这一点很重要：

```java
String[] tokens = "".split("\\s++");
tokens.length; // 1
tokens[0]; // ""
```

当抵达最后的 return 语句，我们将修整过的字符串以一个或多个空格字符切分（`split` 函数可以使用正则表达式），并返回结果数组的长度。

用 Python 写的代码要短很多，这是由于 Python 的 `split` 函数和 Java 相比有很多不同之处，更加适合此类问题。值得注意的是，当对空字符串使用 `split` 时，会返回空数组。这是由于 Python 会在 `split` 之前隐式地调用 `trim` (在Python lingo 中是 `strip`)。

```Java [solution 1]
class Solution {
    public int countSegments(String s) {
        String trimmed = s.trim();
        if (trimmed.equals("")) {
            return 0;
        }
        return trimmed.split("\\s+").length;
    }
}
```

```Python [solution 1]
class Solution:
    def countSegments(self, s):
        return len(s.split())
```

**复杂度分析**

* 时间复杂度 : ${O}(n)$。

    这里用到的内置函数（无论是 Java 还是 Python）的时间复杂度或为 ${O}(n)$，或为 ${O}(1)$ ，故整个算法可以在线性复杂度内完成。

* 空间复杂度 : ${O}(n)$。

    `split` 函数 (不管哪种语言) 返回长度为 ${O}(n)$ 的数组/列表，故算法使用线性的额外空间。

---

#### 方法二：原地法 【通过】

**直觉**

如果无法容忍线性的额外空间，可以使用在线性时间和常数空间内解决问题的简单算法。

**算法**

计算单词的数量，就等同于计数单词开始的下标个数。因此，只需要定义好下标的条件，就可以遍历整个字符串，检测每个下标。定义如下：若该下标前为空格（或者为初始下标），且自身不为空格，则其为单词开始的下标。该条件可以以常数时间检测。最后，返回满足条件的下标个数。

```Java [solution 2]
class Solution {
    public int countSegments(String s) {
        int segmentCount = 0;

        for (int i = 0; i < s.length(); i++) {
            if ((i == 0 || s.charAt(i-1) == ' ') && s.charAt(i) != ' ') {
                segmentCount++;
            }
        }

        return segmentCount;
    }
}
```

```Python [solution 2]
class Solution:
    def countSegments(self, s):
        segment_count = 0

        for i in range(len(s)):
            if (i == 0 or s[i-1] == ' ') and s[i] != ' ':
                segment_count += 1

        return segment_count
```

**复杂度分析**

* 时间复杂度 : ${O}(n)$。

    对每个下标进行常数时间的检测。

* 空间复杂度 : ${O}(1)$。

    只使用了额外的几个整数，因此使用的空间为常数。

---
