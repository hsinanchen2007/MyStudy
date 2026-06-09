遵循记录过程的心态写一下题解。
看到这道题，我的第一反应是[这个题目](https://leetcode-cn.com/problems/rotate-array/)，那不是一模一样的题嘛，只不过旋转方向和数组类型稍微不同。秉着复习的心态，就用旋转数组的方法写一次这个题了。
同那道题，可以利用环形旋转或反转的方式求解：
1. 环形旋转
```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        if (s.length() < 1 || s.length() > 10000) {
            return "";
        }
        int size = s.length();
        n = size - (n % size);
        char[] c = s.toCharArray();
        int count = 0;
        for (int i = 0; count < size; i++) {
            int current = i;
            char prev = c[current];
            do {
                int next = (current + n) % size;
                char tmp = c[next];
                c[next] = prev;
                prev = tmp;
                current = next;
                count++;
            } while (current != i);
        }
        return String.valueOf(c);
    }
}
```
2. 反转
```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        if (s.length() < 1 || s.length() > 10000) {
            return "";
        }
        int size = s.length();
        n = size - (n % size);
        char[] c = s.toCharArray();
        reverse(c, 0, size - 1);
        reverse(c, 0, n - 1);
        reverse(c, n, size - 1);
        return String.valueOf(c);
    }

    private void reverse(char[] arr, int start, int end) {
        while (start < end) {
            char tmp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = tmp;
        }
    }
}
```

复习完了之后就是这道题的常见做法了。
仔细想想这道题，左移字符串字符的操作不就是把字符串的前n个字符丢到字符串后面去吗，这样一来其实就是把字符串的前n个字符和字符串剩余的字符做一个拼接，得到的就是结果了。尤其用的是Java，api都帮我们搞定了，一行代码的事。
```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        return s.substring(n) + s.substring(0, n);
    }
}
```
