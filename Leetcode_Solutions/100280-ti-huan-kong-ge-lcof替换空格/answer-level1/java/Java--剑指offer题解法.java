1）首先遍历字符串求出空格个数；在Java中，String属于不可变类型，需要转换成char数组进行处理；
2）对char数组进行扩容，由‘%20’替代‘ ’，实际上是原字符数组长度增加空格数*2，即tail=length+countBlanks*2；
3）对字符数组进行由后向前的遍历处理：标记两个下标length（原字符数组长度）-1（记p）表示原字符数组的末位字符，tail(扩容后字符数组长度)-1（记q）表示扩容后字符数组的末尾字符；如果p指向的字符为空，则需要作替换处理（q前填充‘0’，‘2’，‘%’并向前移动3，p向前移动1），反之p，q均向前移动1，如此下去，直到p与q指向同一个位置，说明空格已全部替换完成。

```java
public String replaceSpace(String s) {
        int length = s.length();
        char[] chars = s.toCharArray();
        int countBlanks = 0;
        for (char ch: chars) {
            if (ch == ' ') {
                countBlanks++;
            }
        }

        int tail = length + countBlanks * 2;
        chars = Arrays.copyOf(chars, tail);
        while (length != tail) {
            if (chars[length - 1] != ' ') {
                chars[tail - 1] = chars[length - 1];
                length--;
                tail--;
            } else {
                chars[tail - 1] = '0';
                chars[tail - 2] = '2';
                chars[tail - 3] = '%';
                length--;
                tail -= 3;
            }
        }

        return new String(chars);
}
```
